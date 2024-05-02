#include <grpcpp/grpcpp.h>
#include <simplenet.grpc.pb.h>
#include <iostream>

class ClientImpl{
private:
    // Заглушка для просмотра доступных сервисов сервера
    std::unique_ptr<simplenet::Greeter::Stub> stub_;
public:
    ClientImpl(std::shared_ptr<grpc::Channel> channel) 
        : stub_(simplenet::Greeter::NewStub(channel)) {}

    // Собирает запрос, отправляет на сервер, получает ответ
    std::string SayHello(const std::string& userinp_name){
        // Объект запроса
        simplenet::HelloRequest request;
        // Тело запроса
        request.set_name(userinp_name);

        simplenet::HelloReply reply;
        grpc::ClientContext context;
        grpc::CompletionQueue cq;

        // Объект статуса обрабоки запроса сервером
        grpc::Status status;

        std::unique_ptr<grpc::ClientAsyncResponseReader<simplenet::HelloReply>> rpc(
            stub_->AsyncHelloMsg(&context, request, &cq));

        // По завершении процедуры запросить ответ и статус обработки запроса
        rpc->Finish(&reply, &status, (void*)1);
        void* got_tag;
        bool ok = false;
        // Проверяет есть ли в очереди выполнения следующий запрос
        GPR_ASSERT(cq.Next(&got_tag, &ok));

        // Проверяет что тег ответа соответствует тегу нашего запроса
        GPR_ASSERT(got_tag == (void*)1);
        // Проверяет что реквест был обработан успешно
        GPR_ASSERT(ok);

        // Действие с ответом при успешной обработке запроса
        if (status.ok()){
            return reply.message() + ' ' + reply.datetime();
        } 
        else{
            return "RPC failed";
        }
    }
};

int main(){
    ClientImpl greeter(grpc::CreateChannel("127.0.0.1:8081", grpc::InsecureChannelCredentials()));
    std::string user("Artem");
    // Вызов RPC
    std::string reply = greeter.SayHello(user);
    // Вывод ответа сервера на запрос
    std::cout << "Server's reply: " << reply << std::endl;

    return EXIT_SUCCESS;
}
