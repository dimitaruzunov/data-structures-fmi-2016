#include <iostream>
#include <queue>
#include <string>

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::string;

struct Person {
  string name;
  bool isWoman;
};

istream& operator>>(istream& in, Person& person) {
  in >> person.name;
  char sex;
  in >> sex;
  person.isWoman = (sex == 'F');

  return in;
}

ostream& operator<<(ostream& out, Person& person) {
  out << person.name << " ";

  return out;
}

class Lobby {
  queue<Person> people;

public:

  bool empty() {
    return people.empty();
  }

  void addPerson(Person p) {
    people.push(p);
  }

  void process() {
    int size = people.size();
    bool processedWoman = false;
    for (int i = 0; i < size; ++i) {
      if (!processedWoman && people.front().isWoman) {
        cout << people.front();
        processedWoman = true;
      } else {
        people.push(people.front());
      }
      people.pop();
    }

    if (!processedWoman) {
      cout << people.front();
      people.pop();
    }
  }
};

void processQueue() {
  int n;
  queue<Person> q;

  cin >> n;
  Person person;
  char sex;
  for (int i = 0; i < n; ++i) {
    cin >> person.name;
    cin >> sex;
    person.isWoman = (sex == 'F');
    q.push(person);
  }

  Lobby lobby;
  for (int i = 0; i < 5; ++i) {
    if (!q.empty()) {
      lobby.addPerson(q.front());
      q.pop();
    }
  }
  while (!q.empty()) {
    lobby.process();
    lobby.addPerson(q.front());
    q.pop();
  }
  while (!lobby.empty()) {
    lobby.process();
  }

}

int main() {
  processQueue();

  return 0;
}