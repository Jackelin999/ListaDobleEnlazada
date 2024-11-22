#include <iostream>
using namespace std;

class Nodo {
public:
    int d; 
    Nodo* s; 
    Nodo* a; 
    Nodo(int v) : d(v), s(nullptr), a(nullptr) {
	}
};

class ListaDoble {
private:
    Nodo* c; 
    Nodo* t; 

public:
    ListaDoble() : c(nullptr), t(nullptr) {
	}

    
    void agrNodo(int d) {
        Nodo* n = new Nodo(d);
        if (!c) {
            c = t = n;
        } else {
            t->s = n;
            n->a = t;
            t = n;
        }
        cout << "Nodo con dato " << d << " agregado.\n";
    }

    
void elmNodo(int d) {
        Nodo* act = c;
        while (act) {
            if (act->d == d) {
                if (act->a) {
                    act->a->s = act->s;
                } else {
                    c = act->s;
                }
                if (act->s) {
                    act->s->a = act->a;
                } else {
                    t = act->a;
                }
                delete act;
                cout << "Nodo con dato " << d << " eliminado.\n";
                return;
            }
            act = act->s;
        }
        cout << "No se encontro un nodo con el dato " << d << ".\n";
}

    
void modDato(int dViejo, int dNuevo) {
        Nodo* act = c;
        while (act) {
            if (act->d == dViejo) {
                act->d = dNuevo;
                cout << "Dato modificado: " << dViejo << " -> " << dNuevo << ".\n";
                return;
            }
            act = act->s;
        }
        cout << "No se encontro un nodo con el dato " << dViejo << ".\n";
}

    
void mosLista() {
        Nodo* act = c;
        if (!act) {
            cout << "La lista esta vacia.\n";
            return;
        }
        cout << "Lista: ";
        while (act) {
            cout << act->d << " ";
            act = act->s;
        }
        cout << "\n";
}

   
void ordLista() {
        if (!c || !c->s) {
            cout << "No hay suficientes elementos para ordenar.\n";
            return;
        }
        bool interc;
        do {
            interc = false;
            Nodo* act = c;
            while (act->s) {
                if (act->d > act->s->d) {
                    swap(act->d, act->s->d);
                    interc = true;
                }
                act = act->s;
            }
        } while (interc);
        cout << "Lista ordenada.\n";
}

    
void borLista() {
        Nodo* act = c;
        while (act) {
            Nodo* temp = act;
            act = act->s;
            delete temp;
        }
        c = t = nullptr;
        cout << "Todos los nodos han sido eliminados.\n";
    }

    ~ListaDoble() {
        borLista();
    }
};

int main() {
    ListaDoble lista;
    int op = 0, d, dViejo, dNuevo;

    while (op != 7) {
        cout << "\nMenu\n";
        cout << "1. Agregar nodo\n";
        cout << "2. Eliminar nodo\n";
        cout << "3. Modificar dato\n";
        cout << "4. Mostrar lista\n";
        cout << "5. Ordenar lista\n";
        cout << "6. Borrar todos los nodos\n";
        cout << "7. Salir\n";
        cout << "Elige una opcion: ";
        cin >> op;

        switch (op) {
            case 1:
                cout << "Ingresa el dato: ";
                cin >> d;
                lista.agrNodo(d);
                break;
            case 2:
                cout << "Ingresa el dato a eliminar: ";
                cin >> d;
                lista.elmNodo(d);
                break;
            case 3:
                cout << "Ingresa el dato a modificar: ";
                cin >> dViejo;
                cout << "Ingresa el nuevo dato: ";
                cin >> dNuevo;
                lista.modDato(dViejo, dNuevo);
                break;
            case 4:
                lista.mosLista();
                break;
            case 5:
                lista.ordLista();
                break;
            case 6:
                lista.borLista();
                break;
            case 7:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    }

    return 0;
}
