
#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;

		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista j� possuir elementos
	// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
	}
	else
	{
		// procura o final da lista
		NO* aux = primeiro;
		while (aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = novo;
	}
}

void excluirElemento()
{

	int elementoExcluir;
	NO* aux = primeiro;

	if (primeiro == NULL) {
		cout << "Lista vazia, n�o h� elementos para excluir!" << endl;
		return;
	}

	cout << "Escreva um elemento a ser exclu�do: ";
	cin >> elementoExcluir;

	if (primeiro->valor == elementoExcluir) {
		NO* aux = primeiro;
		primeiro = primeiro->prox;
		free(aux);
		cout << "Elemento exclu�do!" << endl;
		return;
	}

	while (aux->prox != NULL) {
		if (aux->prox->valor == elementoExcluir) {
			NO* elementoRemover = aux->prox;
			aux->prox = aux->prox->prox;
			free(elementoRemover);
			cout << "Elemento exclu�do!" << endl;
			return;
		}
		aux = aux->prox;
	}

	cout << "Elemento n�o encontrado!" << endl;
}


void buscarElemento()
{

	int elementoBuscar;
	cout << "Digite o elemento a ser buscado: ";
	cin >> elementoBuscar;

	NO* aux = primeiro;

	while (aux != NULL) {
		if (aux->valor == elementoBuscar) {
			cout << "Elemento " << elementoBuscar << " encontrado!" << endl;
			return;
		}
		aux = aux->prox;
	}

	cout << "Elemento n�o encontrado!" << endl;
}



// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento n�o estiver na lista
NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}