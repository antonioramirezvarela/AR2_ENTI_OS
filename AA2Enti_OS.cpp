#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

struct Usuario {
    string nombre;
    string contrasenya;
};

struct Tarea {
    string nombre;
    bool completada;
};

unordered_map<string, Usuario> usuarios;
string usuarioElegido;

void crearUsuario() {
    Usuario nuevoUsuario;
    cout << "Ingrese el nombre del nuevo usuario: ";
    cin >> nuevoUsuario.nombre;
    cout << "Ingrese la contraseña del nuevo usuario: ";
    cin >> nuevoUsuario.contrasenya;
    usuarios[nuevoUsuario.nombre] = nuevoUsuario;
    cout << "Usuario creado exitosamente.\n";
}

void modificarContrasenya() {
    cout << "Ingrese su nombre de usuario: ";
    cin >> usuarioElegido;

    if (usuarios.find(usuarioElegido) != usuarios.end()) {
        cout << "Ingrese la nueva contraseña: ";
        cin >> usuarios[usuarioElegido].contrasenya;
        cout << "Contraseña modificada exitosamente.\n";
    }
    else {
        cout << "Usuario no encontrado.\n";
    }
}

void eliminarUsuario() {
    cout << "Ingrese su nombre de usuario: ";
    cin >> usuarioElegido;

    if (usuarios.find(usuarioElegido) != usuarios.end()) {
        usuarios.erase(usuarioElegido);
        cout << "Usuario eliminado exitosamente.\n";
    }
    else {
        cout << "Usuario no encontrado.\n";
    }
}

void GestionarUsuario() {
    int opcion_usuario;
    do {
        cout << "\nUser: Admin\n";
        cout << "\nGestionar Usuarios: \n";
        cout << "1- Crear usuario\n";
        cout << "2- Modificar constraseña\n";
        cout << "3- Eliminar usuario\n";
        cout << "4- Volver\n";
        cout << "Ingrese su elección: ";
        cin >> opcion_usuario;

        switch (opcion_usuario) {
        case 1:
            cout << "Entrando al menú para crear usuario...\n";
            crearUsuario();
            break;
        case 2:
            cout << "Entrando al menú para modificar contraseña...\n";
            modificarContrasenya();
            break;
        case 3:
            cout << "Entrando al menú para eliminar usuario...\n";
            eliminarUsuario();
            break;
        case 4:
            cout << "Volviendo al menú principal\n";
            break;
        default:
            cout << "Opcion no valida. Inténtelo de nuevo\n";
        }
    } while (opcion_usuario != 4);
}

void crearDirectorio(vector<string>& directorios) {
    string nombreDirectorio;
    cout << "Ingrese el nombre del nuevo directorio: ";
    cin >> nombreDirectorio;
    directorios.push_back(nombreDirectorio);
    cout << "Directorio creado exitosamente.\n";
}

void renombrarDirectorio(vector<string>& directorios) {
    string directorioAntiguo, directorioNuevo;
    cout << "Ingrese el nombre del directorio que desea renombrar: ";
    cin >> directorioAntiguo;
    cout << "Ingrese el nuevo nombre para el directorio: ";
    cin >> directorioNuevo;

    auto it = find(directorios.begin(), directorios.end(), directorioAntiguo);
    if (it != directorios.end()) {
        *it = directorioNuevo;
        cout << "Directorio renombrado exitosamente.\n";
    }
    else {
        cout << "Error al renombrar el drectorio. Asegúrese de que el directorio exista.\n";
    }
}

void eliminarDirectorios(vector<string>& directorios) {
    string directorioEliminar;
    cout << "Ingrese el nombre del directorio que desea eliminar: ";
    cin >> directorioEliminar;

    auto it = find(directorios.begin(), directorios.end(), directorioEliminar);
   if (it != directorios.end()) {
       directorios.erase(it);
        cout << "Directorio eliminado exitosamente.\n";
    }
    else {
        cout << "Error al eliminar el directorio. Asegúrese de que el directorio exista.\n";
    }
}


void verDirectorios(const vector<string>& directorios) {
    cout << "Directorios Actuales\n";
    for (const auto& directorio : directorios) {
        cout << directorio << endl;
    }
}



void GestionarDirectorios() {
    int opcion_directorios;
    vector<string> directorios;
    do {
        cout << "\nUser: Admin\n";
        cout << "\nGestionar Directorios: \n";
        cout << "1- Ver directorios\n";
        cout << "2- Crear directorios\n";
        cout << "3- Renombrar directorio\n";
        cout << "4- Eliminar directorio\n";
        cout << "5- Volver\n";
        cout << "Ingrese su elección: ";
        cin >> opcion_directorios;

        switch (opcion_directorios) {
        case 1:
            cout << "Entrando al menú para ver directorios\n";
            verDirectorios(directorios);
            break;
        case 2:
            cout << "Entrando al menú para crear directorios\n";
            crearDirectorio(directorios);
            break;
        case 3:
            cout << "Entrando al menú para renombrar directorio\n";
            renombrarDirectorio(directorios);
            break;
        case 4:
            cout << "Entrando al menú para eliminar directorio\n";
            eliminarDirectorios(directorios);
            break;
        case 5:
            cout << "Volviendo al menú principal\n";
            break;
        default:
            cout << "Opción no válida. Inténtelo de nuevo\n";
        }


    } while (opcion_directorios != 5);
}

void crearTarea(vector<Tarea>& listaTareas) {
    Tarea nuevaTarea;
    cout << "Ingrese el nombre de la nueva tarea: ";
    cin.ignore(); // Limpiar el buffer deentrada anted de getline
    getline(cin, nuevaTarea.nombre);
    nuevaTarea.completada = false;
    listaTareas.push_back(nuevaTarea);
    cout << "Tarea creada exitosamente.\n";
}

void siguienteTarea(const vector<Tarea>& listaTareas) {
    bool tareaEncontrada = false;

    for (const Tarea& tarea : listaTareas) {
        if (!tarea.completada) {
            cout << "Siguiente tarea: " << tarea.nombre << endl;
            tareaEncontrada = true;
            break;
        }
    }

    if (!tareaEncontrada) {
        cout << "No hay tareas pendientes.\n";
    }
}

void completarTarea(vector<Tarea>& listaTareas) {
    string nombreTarea;
    cout << "Ingrese el nmbre de la tarea a completar: ";
    cin.ignore();
    getline(cin, nombreTarea);

    for (Tarea& tarea : listaTareas) {
        if (tarea.nombre == nombreTarea) {
            if (!tarea.completada) {
                tarea.completada = true;
                cout << "Tarea completada exitosamente.\n";
            }
            else {
                cout << "Esta tarea ya está completada.\n";
            }
            return;
        }
    }
    cout << "No se encontró la tarea con el nombre especificado.\n";
}


void GestionarTareas() {
    vector<Tarea> listaTareas;
    int opcion_tareas;

    do {
        cout << "\nUser: Admin\n";
        cout << "1- Crear tarea\n";
        cout << "2- Mostrar siguiente tarea\n";
        cout << "3- Completar tarea\n";
        cout << "4- Volverr\n";
        cout << "Ingrese su elección: ";
        cin >> opcion_tareas;

        switch (opcion_tareas) {
        case 1:
            cout << "Entrando al menú para crear tarea...\n";
            crearTarea(listaTareas);
            break;
        case 2:
            cout << "Entrando al menú para mostrar siguiente tarea...\n";
            siguienteTarea(listaTareas);
            break;
        case 3:
            cout << "Entrando al menú para completar tarea...\n";
            completarTarea(listaTareas);
            break;
        case 4:
            cout << "Volviendo al menú principal...\n";
            break;
        default:
            cout << "Opción no válida. Inténtelo de nuevo...\n";
        }

    } while (opcion_tareas != 4);
}

void CambiarUsuario(vector<Usuario>& usuarios, string& usuarioActual) {
    string nombreUsuario;
    cout << "Ingrese el nombre de usuario al que desea cambiar: ";
    cin >> nombreUsuario;

    for (const auto& usuario : usuarios) {
        if (usuario.nombre == nombreUsuario) {
            usuarioActual = nombreUsuario;
            cout << "Cambiado a usuario: " << nombreUsuario << endl;
            return;
        }
    }
    cout << "Usuario no encontrado.\n";
}


// Funciones para el menú del usuario no Admin
void menu_principal_invitado() {
    int opcion_invitado;
    do {
        cout << "\nUser: Invitado\n";
        cout << "\nMenú Principal\n";
        cout << "1- Cambiar usuario\n";lo
        cout << "2- Gestionar directorios\n";
        cout << "3- Cambiar tareas\n";
        cout << "4- Volver\n";
        cout << "Ingrese su elección: ";
        cin >> opcion_invitado;

        switch (opcion_invitado) {
        case 1:
            // Funcionalidad para cambiar usuario
            break;
        case 2:
            cout << "Entrando al menú para gestionar directorios...\n";
            GestionarDirectorios();
            break;
        case 3:
            cout << "Entrando al menú para gestionar tareas...\n";
            GestionarTareas();
            break;
        case 4:
            cout << "Volviendo al menú principal...\n";
            break;
        default:
            cout << "Opción no válida. inténtelo de nuevo...\n";
        }
    } while (opcion_invitado != 4);
}

// Funciones para el menu del administrador
void menu_principal_admin() {
    int opcion_admin;
     do {
           cout << "\nUser: Admin\n";
           cout << "\nMenú Principal\n";
           cout << "1- Gestionar usuario\n";
           cout << "2- Cambiar usuario\n";
           cout << "3- Gestionar directorios\n";
           cout << "4- Gestionar tareas\n";
           cout << "5- Salir\n";
           cout << "Ingrese su elección: ";
           cin >> opcion_admin;

           switch (opcion_admin) {
            case 1:
                GestionarUsuario();
                break;
            case 2:
                GestionarDirectorios();
                break;
            case 3:
                GestionarTareas();
                break;
            case 4:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida. Inténtelo de nuevo...\n";
            }
        } while (opcion_admin != 5);
    }

int main() {
    int opcion_principal;
    do {
        cout << "\nBienvenido al Sitema de Gestion\n";
        cout << "1- Ingresar como Admin\n";
        cout << "2- Ingresar como Invitado\n";
        cout << "3- Salir\n";
        cout << "Ingrese su eleccion: ";
        cin >> opcion_principal;

        switch (opcion_principal) {
        case 1:
            menu_principal_admin();
            break;
        case 2:
            menu_principal_invitado();
            break;
        case 3:
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opcion no valida. Intentelo de nuevo...\n";
        }
    } while (opcion_principal != 3);


    return 0;
}