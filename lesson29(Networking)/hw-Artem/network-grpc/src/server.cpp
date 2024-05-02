#include <grpcpp/grpcpp.h>
#include <simplenet.grpc.pb.h>
#include <Logger.hpp>


class ServerImpl final{
private:
    // Сервис приветствия клиента
    class GreeterServiceImpl{
    private:
        // Метод сервиса для асинхронного взаимодействия в рантайме
        simplenet::Greeter::AsyncService* service_;
        // Очередь продюсер-консумер для асинхронной нотификации сервера
        grpc::ServerCompletionQueue* cq_;
        // Контекст для rpc (передача метаданных)
        grpc::ServerContext ctx_;
        // Запрос
        simplenet::HelloRequest request_;
        // Ответ
        simplenet::HelloReply reply_;
        // Метод для обращения к клиенту
        grpc::ServerAsyncResponseWriter<simplenet::HelloReply> responder_;
        // Показывает текущее состояние обработки запроса
        enum CallStatus { CREATE, PROCESS, FINISH };
        CallStatus status_;
    public:
        // Принимает экземпляр сервиса и очередь запросов (а также устанавливает контекст для ответа клиенту и статус запроса)
        GreeterServiceImpl(simplenet::Greeter::AsyncService* service, grpc::ServerCompletionQueue* cq)
            : service_(service), cq_(cq), responder_(&ctx_), status_(CREATE) {
            // Обрабатывает запрос
            HandleRequest();
        }

        grpc::Status HandleRequest() {
            if (status_ == CREATE) {
                // Установить статус запроса "В процессе"
                status_ = PROCESS;

                // RequestHelloMsg - начать обработку запроса методом HelloMsg
                // this - присваивает этому запросу уникальный тег (адрес памяти экземпляра сервиса)
                // т.е. разные экземпляры HandleRequest() обрабатывают запросы одновременно
                service_->RequestHelloMsg(&ctx_, &request_, &responder_, cq_, cq_, this);
            } 
            else if (status_ == PROCESS) {
                // Инициализировать в Куче новый экземпляр HandleRequest() для обработки нового запроса (пока обрабатывается старый)
                new GreeterServiceImpl(service_, cq_);

                // Логирование
                std::cout << "New connection" << std::endl;
                Logger::self().write("MSG: New connection");

                // Непосредственно обработка запроса
                reply_.set_message("Hello, " + request_.name() + '!');
                reply_.set_datetime("Current date and time is: " + Logger::self().getTimeStamp());

                // Указывает наш ответ, статус ОК и адрес памяти текущего экземпляра сервиса
                status_ = FINISH;
                responder_.Finish(reply_, grpc::Status::OK, this);
            }
            else {
                GPR_ASSERT(status_ == FINISH);
                // Деаллокация текущего экземпляра сервиса
                delete this;
            }
            return grpc::Status::OK;
        }
    };
    
private:
    std::unique_ptr<grpc::ServerCompletionQueue> cq_;
    simplenet::Greeter::AsyncService service_;
    std::unique_ptr<grpc::Server> server_;
public:
    ~ServerImpl(){
        server_->Shutdown();
        cq_->Shutdown();
        Logger::self().write("MSG: ---SESSION ENDED---");
        Logger::self().~Logger();
    }

    void ServerRun(const std::string server_address){
        grpc::ServerBuilder builder;

        // Сокет слушает по адресу ...
        builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

        // Добавить на сервер экземпляр моего сервиса для взаимодействия с клиентами
        builder.RegisterService(&service_);

        // Присвоить очередь выполнения
        cq_ = builder.AddCompletionQueue();
        
        // Собрать сервер
        server_ = builder.BuildAndStart();
        std::cout << "Server listening on " << server_address << std::endl;
        Logger::self().write("MSG: Server listening on " + server_address);

        // Главный цикл сервера в котором обрабатываются все запросы клиентов
        HandleRpcs();
    }
private:
    void HandleRpcs(){
        // Инициализировать в Куче новый экземпляр сервиса для обработки запроса
        new GreeterServiceImpl(&service_, cq_.get());
        // Уникальный тег для идентификации запроса
        void* tag;
        bool ok;
        // Цикл ждет следующего эвента из Очереди запросов
        while (true) {
            // Каждый эвент идентифицируется по адресу памяти вызвавшего его экземпляра сервиса 
            GPR_ASSERT(cq_->Next(&tag, &ok));
            GPR_ASSERT(ok);
            static_cast<GreeterServiceImpl*>(tag)->HandleRequest();
        }
    }
};



int main(){
    Logger::self().createLogFile();
    Logger::self().write("MSG: ---NEW SESSION STARTED---");

    ServerImpl myServer;
    myServer.ServerRun("127.0.0.1:8081");

    return EXIT_SUCCESS;
}