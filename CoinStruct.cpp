#include "CoinStruct.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	
	Wallet wallet;

	while (true) {
		cout << "Выберите действие:" << endl;
		cout << "0. Загрузить кошелёк из файла" << endl;
		cout << "1. Добавить монету по названию" << endl;
		cout << "2. Добавить монету по ценности" << endl;
		cout << "3. Удалить монету по названию" << endl;
		cout << "4. Удалить монету по ценности" << endl;
		cout << "5. Подсчитать количество уникальных монет" << endl;
		cout << "6. Найти монету по названию" << endl;
		cout << "7. Найти монету по ценности" << endl;
		cout << "8. Отcортировать монеты по возрастанию" << endl;
		cout << "9. Отобразить содержимое кошелька" << endl;
		cout << "10. Выйти" << endl;
		cout << "11. Выбросить все монеты" << endl;

		int choice;
		cin >> choice;


		// Wallet 1. "C:\\Users\\smart\\source\\repos\\CoinStruct\\CoinStruct\\Wallet1.txt"
		// Wallet 2. "C:\\Users\\smart\\source\\repos\\CoinStruct\\CoinStruct\\Wallet2.txt"
		// Wallet 3. "C:\\Users\\smart\\source\\repos\\CoinStruct\\CoinStruct\\Wallet3.txt"

		switch (choice) {
		case 0: {
			string filepath;
			cout << "Выберите кошелёк: Wallet1, Wallet2, Wallet3" << endl;
			cin >> filepath;
			wallet.readCoinsFromFile("C:\\Users\\smart\\source\\repos\\CoinStruct\\CoinStruct\\" + filepath + ".txt");
			break;
		}
		case 1: {
			string name;
			int value;
			cout << "Введите название монеты: ";
			cin >> name;
			cout << "Введите ценность монеты: ";
			cin >> value;
			wallet.addCoinByName(name, value);
			break;
		}
		case 2: {
			int value;
			cout << "Введите ценность монеты: ";
			cin >> value;
			wallet.addCoinByValue("None", value);
			break;
		}
		case 3: {
			string name;
			cout << "Введите название монеты для удаления: ";
			cin >> name;
			wallet.removeCoinByName(name);
			break;
		}
		case 4: {
			int value;
			cout << "Введите ценность монеты для удаления: ";
			cin >> value;
			wallet.removeCoinByValue(value);
			break;
		}
		case 5: {
			int count = wallet.countUniqueCoins();
			cout << "Уникальные монеты в кошельке: " << count << endl;
			break;
		}
		case 6: {
			string name;
			cout << "Введите название монеты для поиска: ";
			cin >> name;
			bool found = wallet.findCoinByName(name);
			cout << "Монета найдена: " << boolalpha << found << endl;
			break;
		}
		case 7: {
			int value;
			cout << "Введите ценность монеты для поиска: ";
			cin >> value;
			bool found = wallet.findCoinByValue(value);
			cout << "Монета найдена: " << boolalpha << found << endl;
			break;
		}
		case 8: {
			wallet.sortCoinsAscending();
			break;
		}
		case 9: {
			wallet.displayWalletContent();
			break;
		}
		case 10: {
			cout << "До свидания!" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			exit(0);
			return 0;
		}
		case 11: {
			char confirm;
			cout << "Вы уверены, что хотите очистить кошелек? (Y/N): ";
			cin >> confirm;
			if (confirm == 'Y' || confirm == 'y') {
				wallet.clearWallet();
			}
			else {
				cout << "Очистка кошелька отменена." << endl;
			}
			break;
		}
		default:
			cout << "Некорректный ввод. Попробуйте снова." << endl;
		}
	}
	system("pause");
	return 0;
}