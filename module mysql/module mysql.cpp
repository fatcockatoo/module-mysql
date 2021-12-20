# include <winsock2.h> //сокеты вонючие сдохните
#include <ctime> // подключаем clock
#include <string> // строчечки
#include <iostream>
#include <Ws2tcpip.h>
using namespace std;

/*
struct sockaddr_in {
    short sin_family;
    unsigned short sin_port;
    struct in_addr sin_addr;
    char sin_zero[8];
};*/

int connect() {
    int sock = 0, n;
    struct sockaddr_in serv_addr;
    struct hostent* server;
    int const BUFFER_SIZE = 1024;// Адрес сервера и порт
    char* buffer = new char[BUFFER_SIZE];
    char* hello = new char[BUFFER_SIZE];
    int portno = 2414;
    string server = "78.24.217.186";//address_to_server = ('localhost', 8686); python origin//Имя пользователя, полученное через параметры запуска(первый параметр) и код вашего приложения
    string USERNAME = "dengadiplom";
    string APP = "F";//Сообщение, отправляемое на сервер.Получаем строку LICENCE - dengadiplom - B(licence - сущ.license - глагол)0))0)0))
    string message = "LICENCE-" + USERNAME + "-" + APP;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_family = AF_INET;
    hello = (char*)&message;

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    send(sock, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    // int valread = read(sock, buffer, 1024);
 //   printf("%s\n", buffer);

   /* try {//Подключение к серверу
        client = socket.socket(socket.AF_INET, socket.SOCK_STREAM);
        client.connect(address_to_server);//Отправляем сообщение, кодировка utf - 8 (это обязательно!)
        message = message.encode("utf-8");
        client.send(message);
        data = client.recv(BUFFER_SIZE);//олучаем результат результат и декодируем(тоже utf - 8)
        data = data.decode('utf-8');
        print(data);
        if (data == 'OK') {
            print("Включаем приложение"); //Открываем окно через поток или типа того
            bool pony = True;//Включаем магию
            while (pony) {
                data = client.recv(BUFFER_SIZE);
                data = data.decode("utf-8");
                print(data); //Раз в минуту от сервера приходит сообщение "ОК" ///В идеале сделать так, чтобы в случае если пришло что - то другое, программа закрывалась//сорян володь я нихуя не сделаю
                if (data != 'OK') {
                    break;//После выхода закрыть соединение
                    client.close();
                }
            }
        }
        else if (data == 'NO')
        {
            cout << ("Открываем окно типа нет доступа к бизнес - приложенмию обратитесь к администратору ИС бла бла бла и отключаемся");
            client.close();
        }
    }
    catch () { socket.error
        cout << (("Вывести окно с ошибкой соединения с сервером");
        }*/
}