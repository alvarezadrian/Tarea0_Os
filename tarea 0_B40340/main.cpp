#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "embellecer.h"
using namespace std;

/*
	EFE: Lee el archivo con el codigo a justificar y guarda su contenido en una nueva hilera.
	REQ: file existente.
	MOD: N/A.
*/
string fileContentToString(char* file){
    fstream fileContent (file);
    string contentRead = "";
    string line = "";
    while (getline(fileContent, line)) {
        contentRead = contentRead + line + "\n";
    }
    return contentRead;
}
/*
	EFE: Solicita datos al usuario desde consola hasta que ingrese la palabra *terminate en una nueva linea.*
	REQ: N/A.
	MOD: N/A.
*/
string getFromConsole(){
	string readCode = "";
	string line = "";
	bool terminate = false;
	cout<<"Ingrese el codigo que desea justificar.\n Escriba *terminate* en una nueva linea para detener la solicitud de texto.\n";
		while(getline(std::cin, line) && line != "*terminate*"){//Solicitud de datos.
			readCode += line;
			readCode += "\n";
		}
		
	return readCode;
}

int main(int argc, char** argv) {
    int tabSize = 4;
    Embellecer *e;
    string tabSizeStr = "";//variable que guarda la cantidad de espacios de tabulación en caso que sean ingresados en la ejecución.
    string received = ""; //Variable que guarda la hilera con el código a justificar en caso que sea por la entrada estandar..
    string fileContent = ""; //Variable que guarda la hilera a justificar en caso de que fuera ingresada una hilera.
    string outFileName = "rst.txt"; //Variable para nombrar guardar el nombre del archivo de salida.
    string fInstruction = ""; //Variable que se usa para obtener los datos que da el usuario en comandos.
    ofstream x ("cuentaDePalabrasReservadas.txt"); //Creación del archivo con la cuenta del uso de palabras reservadas.
	
    switch(argc){
        case 1: //Sin argumentos.
        {	
			received = getFromConsole();
            e = new Embellecer(received, tabSize);
            ofstream outFile (outFileName);
            outFile << e->processContent();
			cout<<e->processContent();
            x << e->createUsedWords();
        }
            break;
        case 2:
        {
            if(argv[1][0]=='-'){
                if(argv[1][1] == 'e'){//-eX
                    fInstruction = argv[1];
					tabSizeStr = fInstruction.substr(2);
					tabSize = stoi(tabSizeStr);
					if(tabSize < 0){
						cout<<"No se aceptan numeros negativos para tabular.\n";
						return -1;
					}
                } else {//-oX
                    fInstruction = argv[1];
                    outFileName = fInstruction.substr(2);
                }
				
                received = getFromConsole();
                e = new Embellecer(received, tabSize);
                ofstream outFile (outFileName);
                outFile << e->processContent();
                x << e->createUsedWords();
            } else {//fileToJustify
                fileContent = fileContentToString(argv[1]);
                e = new Embellecer(fileContent,tabSize);
                ofstream outFile (outFileName);
                outFile << e->processContent();
                x << e->createUsedWords();
            }
        }
            break;
        case 3:
        {
            if(argv[1][0] == '-'){
                if(argv[2][0] == '-'){//-eX -o
					fInstruction = argv[1];
					tabSizeStr = fInstruction.substr(2);
					tabSize = stoi(tabSizeStr);
					if(tabSize < 0){
						cout<<"No se aceptan numeros negativos para tabular.\n";
						return -1;
					}
                    fInstruction = argv[2];
                    outFileName = fInstruction.substr(2);
					
                    received = getFromConsole();
					
                    e = new Embellecer(received, tabSize);
                    ofstream outFile (outFileName);
                    outFile << e->processContent();
                    x << e->createUsedWords();
                } else {//-eX fileToJustify.
                    fInstruction = argv[1];
					tabSizeStr = fInstruction.substr(2);
					tabSize = stoi(tabSizeStr);
					if(tabSize < 0){
						cout<<"No se aceptan numeros negativos para tabular.\n";
						return -1;
					}
                    fileContent = fileContentToString(argv[2]);
                    e = new Embellecer(fileContent,tabSize);
                    ofstream outFile (outFileName);
                    outFile << e->processContent();
                    x << e->createUsedWords();
                }
            } else {//fileToJustify -o
                    fInstruction = argv[2];
                    fileContent = fileContentToString(argv[1]);
                    e = new Embellecer(fileContent,tabSize);
                    outFileName = fInstruction.substr(2);
                    ofstream outFile (outFileName);
                    outFile << e->processContent();
                    x << e->createUsedWords();
            }
            break;
        }
        case 4:
        {//-eX fileToJustify -oX
			fInstruction = argv[1];
			tabSizeStr = fInstruction.substr(2);
			tabSize = stoi(tabSizeStr);
					if(tabSize < 0){
						cout<<"No se aceptan numeros negativos para tabular.\n";
						return -1;
					}
			cout << tabSizeStr <<endl;
			cout << tabSize <<endl;
            fInstruction = argv[3];
            fileContent = fileContentToString(argv[2]);
            e = new Embellecer(fileContent,tabSize);
            outFileName = fInstruction.substr(2);
            ofstream outFile (outFileName);
            outFile << e->processContent();
            x << e->createUsedWords();
        }
            break;
    }
    return 0;
}

