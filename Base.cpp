#include <iostream>
using namespace std;
class Base {
	private:
		int mainPage () const {
			int opt;
			cout << "\n**Gerenciamento de Sensores**\n1. Sensores Fixos\n2. Sensores Moveis\n3. Sensores Virtuais\n0. Sair\n\nOpcao: ";
			cin >> opt;
			return opt;
		} 

		void statSensor() const {
			int opt;			
			do {
				cout << "1. Atualizar\t0.Voltar\nOpcao: ";
				cin >> opt;
			} while (opt);
		}

		void mobiSensor() const {
			int opt;			
			do {
				cout << "1. Atualizar\t0.Voltar\nOpcao: ";
				cin >> opt;
			} while (opt);
		}

		void virtSensor() const {
			int opt;			
			do {
				cout << "1. Atualizar\t0.Voltar\nOpcao: ";
				cin >> opt;
			} while (opt);
		}
	
	public:
		void userInterface () const {
			int opt;			
			do{	opt = mainPage ();
				if 	(opt==1) statSensor();
				else if (opt==2) mobiSensor();
				else if (opt==3) virtSensor();
				else if (opt) cout << "Opcao Inválida!\n";
			} while (opt);
		}
};

int main () {
	Base b;
	b.userInterface();
	return 0;
}
