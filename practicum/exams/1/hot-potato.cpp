#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <queue>

using std::cout;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::list;
using std::string;
using std::queue;

list<string> hot_potato(const list<string>& players, int passes) {
  queue<string> circle;
  list<string> players_ranking;

  for (const string& player : players) {
    circle.push(player);
  }

  while (circle.size() > 1) {
    for (int i = 0; i < passes; ++i) {
      const string& current_player = circle.front();
      circle.pop();
      circle.push(current_player);
    }

    players_ranking.push_back(circle.front());
    cout << circle.front() << '\n';
    circle.pop();
  }

  players_ranking.push_back(circle.front());
  cout << circle.front() << '\n';
  circle.pop();

  return players_ranking;
}

list<string> read_game(const char* game_input_file, int& passes) {
  ifstream file(game_input_file);

  int number_of_players;
  file >> number_of_players;

  list<string> players;

  for (int i = 0; i < number_of_players; ++i) {
    string current_player;
    file >> current_player;
    players.push_back(current_player);
  }

  file >> passes;

  file.close();

  return players;
}

void write_game(const list<string>& players_ranking, const char* game_output_file) {
  ofstream file(game_output_file);

  for (const string& player : players_ranking) {
    file << player << '\n';
  }

  file.close();
}

void write_game_binary(const list<string>& players_ranking, const char* game_output_file) {
  ofstream file(game_output_file, ios::binary);

  for (const string& player : players_ranking) {
    file.write((player + "\n").c_str(), player.size() + 1);
  }
}

void read_game_results(const char* game_output_file) {
  ifstream file(game_output_file, ios::binary);

  const int BUFFER_SIZE = 100;
  char buffer[BUFFER_SIZE];

  long read_count = 0;
  while ((read_count = file.read(buffer, BUFFER_SIZE - 1).gcount())) {
    buffer[read_count] = '\0';
    cout << buffer;
  }
}

int main() {
  int passes;
  list<string> players = read_game("game-input.txt", passes);

  list<string> players_ranking = hot_potato(players, passes);

  write_game(players_ranking, "game-output.txt");

  write_game_binary(players_ranking, "game-output.bin");

  read_game_results("game-output.bin");

  return 0;
}
