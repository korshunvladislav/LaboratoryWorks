#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
class Message {
public:
    explicit Message(T content) : content_(move(content)) {}

    T get_content() const { return content_; }

private:
    T content_;
};

class User {
public:
    virtual ~User() = default;

    virtual void notify(const string &message) = 0;

    virtual bool can_receive_messages() const = 0;

    virtual string getName() const = 0;
};

class RegularUser : public User {
public:
    explicit RegularUser(string name) : name_(move(name)) {}

    void notify(const string &message) override {
        cout << "Пользователь " << name_ << " получил новое сообщение: " << message << endl;
    }

    bool can_receive_messages() const override {
        return true;
    }

    string getName() const override {
        return name_;
    }

    template <typename T>
    Message<T> generate_message(T content) {
        return Message<T>(content);
    }

private:
    string name_;
};

class Bot : public User {
public:
    explicit Bot(string name) : name_(move(name)) {}

    // Метод notify пустой, так как бот не получает сообщения
    void notify(const string &message) override {}

    bool can_receive_messages() const override {
        return false;
    }

    string getName() const override {
        return name_;
    }

    template <typename T>
    Message<T> generate_message(T content) {
        return Message<T>(content);
    }

private:
    string name_;
};

class MessageServer {
public:
    void add_user(User* user) {
        users_.push_back(user);
    }

    template <typename T>
    void send_message(const Message<T> &message, const User* sender) {
        for (const auto &user : users_) {
            if (user->can_receive_messages() && user != sender) {
                user->notify(content_to_string(message.get_content()));
            }
        }
    }

private:
    template <typename T>
    string content_to_string(const T &content) {
        ostringstream oss;
        oss << content;
        return oss.str();
    }

    vector<User*> users_;
};

int main() {
    MessageServer server;

    RegularUser user1("Alice");
    RegularUser user2("Bob");
    RegularUser user3("Bra");
    Bot bot1("Ket");
    Bot bot2("SkyNetX");

    server.add_user(&user1);
    server.add_user(&user2);
    server.add_user(&user3);
    server.add_user(&bot1);
    server.add_user(&bot2);

    // Сообщение получат все RegularUser'ы
    auto bot_message = bot1.generate_message(42);
    server.send_message(bot_message, &bot1);

    // Сообщение получат все RegularUser'ы
    auto bot_message2 = bot2.generate_message(43);
    server.send_message(bot_message2, &bot2);

    // user1 (Alice) не получит сообщение, так как является отправителем
    auto user_message1 = user1.generate_message("Hello, world!");
    server.send_message(user_message1, &user1);

    return 0;
}
