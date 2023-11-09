#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>

using namespace std;

struct Coin {
	string name;
	int value;
};
struct Wallet {
	map <string, int> coinsByName;
	map <int, string> coinsByValue;
	
	void addCoinByName(const string& name, int value) {
		coinsByName[name] += value;
		coinsByValue[value] = name;

	}
	
	void addCoinByValue(const std::string& name, int value) {
		coinsByName[name] += value;
		coinsByValue[value] = name;
	}
	void removeCoinByName(const string& name) {
		if (coinsByName.find(name) != coinsByName.end()) {
			int value = coinsByName[name];
			coinsByName.erase(name);
			coinsByValue.erase(value);
		}
	}
		void removeCoinByValue(int value) {
			if (coinsByValue.find(value) != coinsByValue.end()) {
				string name = coinsByValue[value];
				coinsByValue.erase(value);
				coinsByName.erase(name);
			}
	}
		int countUniqueCoins() {
			return coinsByName.size();
		}

		bool findCoinByName(const string& name) {
			return coinsByName.find(name) != coinsByName.end();
		}
		bool findCoinByValue(int value) {
			return coinsByValue.find(value) != coinsByValue.end();
		}
		void sortCoinsAscending() {
			vector<pair<int, string>> sortedCoins;

			// Заполняем вектор парами (значение, имя)
			for (const auto& coin : coinsByName) {
				sortedCoins.push_back(make_pair(coin.second, coin.first));
			}

			// Сортируем вектор по возрастанию значения монеты
			sort(sortedCoins.begin(), sortedCoins.end());

			// Выводим содержимое кошелька после сортировки
			cout << "Отсортированное содержимое кошелька:" << endl;
			for (const auto& coin : sortedCoins) {
				cout << coin.second << " - " << coin.first << endl;
			}
		}
		void displayWalletContent() {
			std::cout << "Содержимое кошелька:" << std::endl;
			for (const auto& coin : coinsByName) {
				std::cout << coin.first << " - " << coin.second << std::endl;
			}
		}
		void clearWallet() {
			coinsByName.clear();
			coinsByValue.clear();
			cout << "Кошелек очищен." << endl;
		}
		void readCoinsFromFile(const string& filename) {
			ifstream file(filename);
			if (file.is_open()) {
				string name;
				int value;
				while (file >> name >> value) {
					addCoinByName(name, value);
				}
				file.close();
				cout << "Содержимое кошелька успешно загружено" << endl;
			}
			else {
				cout << "Не удалось открыть файл." << endl;
			}
		}
};