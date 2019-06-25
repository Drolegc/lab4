
void logo(){
system("clear");
std::cout << " " << std::endl;
std::cout << " " << std::endl;
std::cout << " " << std::endl;
std::cout << "                                                            " << std::endl;
std::cout << "           ██╗ ██████╗██╗███╗   ██╗███████╗███╗   ███╗ █████╗ ███████╗          " << std::endl;
std::cout << "           ╚═╝██╔════╝██║████╗  ██║██╔════╝████╗ ████║██╔══██╗██╔════╝          " << std::endl;
std::cout << "           ██╗██║     ██║██╔██╗ ██║█████╗  ██╔████╔██║███████║███████╗          " << std::endl;
std::cout << "           ██║██║     ██║██║╚██╗██║██╔══╝  ██║╚██╔╝██║██╔══██║╚════██║          " << std::endl;
std::cout << "           ██║╚██████╗██║██║ ╚████║███████╗██║ ╚═╝ ██║██║  ██║███████║          " << std::endl;
std::cout << "           ╚═╝ ╚═════╝╚═╝╚═╝  ╚═══╝╚══════╝╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝          " << std::endl;
std::cout << "                                                  PA-CURE-UTEC-G5-2019            \n" << std::endl;
std::cout << " " << std::endl;
system(" aplay 2048MF.wav  > /dev/null 2>&1  ");
}
void lista_comandos(){
std::cout << "                   ╔═════════ MENU DE OPCIONES ═════════════╗                   " << std::endl;
std::cout << "                   ║        1: Agregar cines.               ║░" << std::endl;
std::cout << "                   ║        2: Agregar funcion.             ║░" << std::endl;
std::cout << "                   ║        3: Listar salas                 ║░" << std::endl;
std::cout << "                   ║        4: Salir                        ║░" << std::endl;
std::cout << "                   ╚════════════════════════════════════════╝░" << std::endl;
std::cout << "                    ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n" << std::endl;
}

//std::cout << "            >>>>>>>          PA-CURE-UTEC-G5-2019            <<<<<<<\n" << std::endl;






void muestroCursor(int n){
//std::cout << "  usuario@iCINEMAS:";
std::cout << "                                     seleccione opcion (1.."<<n<<"):";
}