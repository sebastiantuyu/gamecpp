#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
using namespace std;

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

void gotoxy(int actualX, int actualY){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = actualX;
	dwPos.Y = actualY;
	SetConsoleCursorPosition(hcon,dwPos);
}

void hidecursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

int kbhit(void);

int* azar(int num_az[]){
	int i;
	srand(time(NULL));
    for(i=0;i<5;i++){
		num_az[i] = 12+rand()%24;
	}
	
    return num_az;
}

void impO(int x,int y){
	gotoxy(10,10);
	cout<<char(219);	
}

//FUNCION QUE DETERMINA SI CHOCASTE O NO
int mover(int x,int y,int final,int z,int aleatorio[],int nivel){
	int valor, vida,i;
	valor=0;
	
	if((x>=29 && x<=130) && (y>=9 && y<=35)){
		if(nivel>=0){
				if(x==z){
					if(y==aleatorio[0]|y==aleatorio[1]|y==aleatorio[2]|y==aleatorio[3]|y==aleatorio[4]){
					
					valor=0;
					}
					else{
						
					valor=1;
					
					}
			
				
				}
			}
		
}

	if(valor==0){
		gotoxy(x,y);
		cout<<char(219);	
		
		
	}
	
	else if(valor==1){
		
		final = 1;
	}

	


return final;	
}

int moverO(int i,int x_ob,int vel,int aleatorio[],int nivel){
	x_ob = 128-i;
	gotoxy(75,2);
	cout<<nivel;
	
	for(i=9;i<36;i++){
		if(i==aleatorio[0]){
		gotoxy(x_ob+1,i);
		cout<<" ";
		gotoxy(x_ob,i);
		cout<<" ";
		}
		else if(i==aleatorio[1]){
		gotoxy(x_ob+1,i);
		cout<<" ";
		gotoxy(x_ob,i);
		cout<<" ";
		}
		else if(i==aleatorio[2]){
		gotoxy(x_ob+1,i);
		cout<<" ";
		gotoxy(x_ob,i);
		cout<<" ";
		}
		else{
		gotoxy(x_ob+1,i);
		cout<<" ";
		gotoxy(x_ob,i);
		cout<<char(219);
		
		}
		
	}

	
	Sleep(20-(0.3*vel));

	
	
	return x_ob;

}

void imprimeTablero(){
	int i,j;
	//IMPRIMIR ESQUINA IZQUIERDA ARRIBA
		gotoxy(29,8);
		cout<<char(201);
		
	//IMPRIMIR ESQUINA DERECHA ARRIBA
		gotoxy(131,8);
		cout<<char(187);
	
	
	//IMPRIMIR ESQUINA IZQUIERDA ABAJO
		gotoxy(29,36);
		cout<<char(200);
		
	//IMPRIMIR ESQUINA DERECHA ABAJO
		gotoxy(131,36);
		cout<<char(188);
		
		
	//IMPRIMIR LINEA ARRIBA
		for(i=0;i<101;i++){
			gotoxy(30+i,8);
			cout<<char(205);
		}
	//IMPRIMIR LINEA DE ABAJO
		for(i=0;i<101;i++){
			gotoxy(30+i,36);
			cout<<char(205);	
		}
		
	//IMPRIMIR LINEA LATERAL IZQUIERDA
		for(i=0;i<27;i++){
			gotoxy(29,9+i);
			cout<<char(186);	
		}
		
	//IMPRIMIR LINEA LATERAL DERECHA
		for(i=0;i<27;i++){
			gotoxy(131,9+i);
			cout<<char(186);	
		}
		gotoxy(107,37);
		cout<<"PRESIONA M PARA ABANDONAR";
		
		//(75,2)
		gotoxy(74,1);
		cout<<char(201);
		gotoxy(75,1);
		cout<<char(205)<<char(205);
		gotoxy(77,1);
		cout<<char(187);
		
		gotoxy(74,3);
		cout<<char(200);
		gotoxy(75,3);
		cout<<char(205)<<char(205);
		gotoxy(77,3);
		cout<<char(188);
	}

void borrarFinal(int z,int aleatorio[]){
	int i;
	for(i=0;i<27;i++){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
			gotoxy(29,9+i);
			cout<<char(186);
			gotoxy(30,9+i);
			cout<<" ";	
		}
	
	
	
}

void ImprimeGO(){
	int i,j,n=75,cor_y=24; 
	string logo, cara; 
	logo="11111111111111111111111111111111111111111000110001100101011000011001010110110001100100001001011101000010010101010010100110010000100101010110001001010101101010011001011011110101010000100101010100110001100100101001010101000010010101010010100110001100100101010110000110001001101010011111111111111111111111111111111111111111";
	cara ="000000000000000100001000001010010100000000000000001111111100001000000100001000000100000111111000000000000000";			
		for(i=0;i<(logo.length()-2);i+=40){
				for(j=0;j<40;j++){
					
					if(logo[i+j]=='0'){
							gotoxy(60+j,(i/40)+15);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
							cout<<char(219);
							Sleep(5);
					}
					else if(logo[i+j]=='1'){
							gotoxy(60+j,(i/40)+15);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
								cout<<char(219);Sleep(5);
					}
					
					
				}
				cout<<endl; 
		
		
		
			}

//IMPRIMIR CARA


		for(i=0;i<(cara.length()-2);i+=12){
				for(j=0;j<12;j++){
					
					if(cara[i+j]=='0'){
							gotoxy(n+j,(i/12)+cor_y);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
							cout<<char(219);
							Sleep(10);
					}
					else if(cara[i+j]=='1'){
							gotoxy(n+j,(i/12)+cor_y);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
								cout<<char(219);
					}
					else if(cara[i+j]=='3'){
							gotoxy(n+j,(i/12)+cor_y);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
								cout<<char(219);
					}
					
					
				}
				cout<<endl; 
		
		
		
			}

//ANIMACION LAGRIMA

			Sleep(250);
			for(i=0;i<(cara.length()-2);i+=12){
				for(j=0;j<12;j++){
					
						if(cara[i+j]=='3'){
							gotoxy(n+j,(i/12)+cor_y);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
								cout<<char(219);
						}
					
					}
				
					
				}
				cout<<endl; 
			
			
			
			Sleep(300);
			
				for(i=0;i<(cara.length()-2);i+=12){
				for(j=0;j<12;j++){
					
						if(cara[i+j]=='3'){
							gotoxy(n+j,(i/12)+cor_y);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
								cout<<char(219);
								Sleep(150);
						}
					
					}
				
					
				}
				cout<<endl; 

			Sleep(5);
			for(i=0;i<(cara.length()-2);i+=12){
				for(j=0;j<12;j++){
					
						if(cara[i+j]=='3'){
							gotoxy(n+j,(i/12)+cor_y);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
								cout<<char(219);
						}
					
					}
				
					
				}
				cout<<endl; 
			
			
			
			Sleep(300);
			
				for(i=0;i<(cara.length()-2);i+=12){
				for(j=0;j<12;j++){
					
						if(cara[i+j]=='3'){
							gotoxy(n+j,(i/12)+cor_y);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
								cout<<char(219);
								Sleep(150);
						}
					
					}
				
					
				}
				cout<<endl; 


}

void angryBOSS_1(){
	int i,j,n=95,cor_y=18;
	string boss;
	boss="003000000300000300003000001130031100001100001100000000000000000011110000000100001000001000000100001111111100";
	//IMPRIMIR CARA


		for(i=0;i<(boss.length()-2);i+=12){
				for(j=0;j<12;j++){
					
					if(boss[i+j]=='0'){
							gotoxy(n+j,(i/12)+cor_y);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
							cout<<char(219);
							Sleep(10);
					}
					else if(boss[i+j]=='1'){
							gotoxy(n+j,(i/12)+cor_y);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
								cout<<char(219);
					}
					else if(boss[i+j]=='3'){
							gotoxy(n+j,(i/12)+cor_y);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
								cout<<char(219);
					}
					
					
				}
				cout<<endl; 
		
		
		
			}

//ANIMACION ANGRY!!

				Sleep(250);
			for(i=0;i<(boss.length()-2);i+=12){
				for(j=0;j<10;j++){
					
						if(boss[i+j]=='3'){
							gotoxy(n+j,(i/12)+cor_y);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
								cout<<char(219);
						}
					
					}
				
					
				}
				cout<<endl; 
				Sleep(250);
			for(i=0;i<(boss.length()-2);i+=12){
				for(j=0;j<10;j++){
					
						if(boss[i+j]=='3'){
							gotoxy(n+j,(i/12)+cor_y);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
								cout<<char(219);
						}
					
					}
				
					
				}
				cout<<endl; 
				Sleep(250);		
			for(i=0;i<(boss.length()-2);i+=12){
				for(j=0;j<10;j++){
					
						if(boss[i+j]=='3'){
							gotoxy(n+j,(i/12)+cor_y);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
								cout<<char(219);
						}
					
					}
				
					
				}
				cout<<endl; 

}

int deNuevo(){
	int ans,i,j;
	for(i=9;i<36;i++){
		for(j=31;j<131;j++){
			gotoxy(j,i);
			cout<<" ";
		}
		
	}
	
	
	//IMPRIMIR ESQUINA IZQUIERDA ARRIBA
		gotoxy(69,10);
		cout<<char(201);
		
	//IMPRIMIR ESQUINA DERECHA ARRIBA
		gotoxy(84,10);
		cout<<char(187);
	
	
	//IMPRIMIR ESQUINA IZQUIERDA ABAJO
		gotoxy(69,15);
		cout<<char(200);
		
	//IMPRIMIR ESQUINA DERECHA ABAJO
		gotoxy(84,15);
		cout<<char(188);
		
		for(i=0;i<4;i++){
			gotoxy(69,11+i);
			cout<<char(186);
		}for(i=0;i<4;i++){
			gotoxy(84,11+i);
			cout<<char(186);
		}for(i=0;i<14;i++){
			gotoxy(70+i,10);
			cout<<char(205);
		}for(i=0;i<14;i++){
			gotoxy(70+i,15);
			cout<<char(205);
		}
	
		
	gotoxy(71,11);
	cout<<char(168)<<"Reintentar?"<<endl;
	gotoxy(75,12);
	cout<<"SI [0]"<<endl;
	gotoxy(75,13);
	cout<<"NO [1]"<<endl;
	gotoxy(77,14);
	cin>>ans; 
	
	for(i=0;i<15;i++){
		for(j=0;j<20;j++){
			gotoxy(68+j,9+i);
			cout<<" ";
		}
	}
	
	if(ans==1){
		return 1;
	} 
	else if(ans==0){
		return 0;
	}
	
	imprimeTablero();
}

int main(){
	
		ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
		hidecursor();
		
		
		int x=31,y=15,final=0,i=0,x_ob,vel=0,*p,num_az[]={0,0,0,0},nivel=0,final_vida=0,vidas,final_global=0;
		
				//imprimir Objetos()
		
		imprimeTablero();
		p = azar(num_az);
		int aleatorio[]={*p,*(p+1),*(p+2),*(p+3)};
		
		while(final_global==0){
				int z;
				
				z = moverO(i,x_ob,vel,aleatorio,nivel);
				
				if(kbhit()){
				
				char tecla = getch();
				gotoxy(x,y);cout<<" ";
					 if(tecla=='w'|tecla=='W'){if(y<10){}else{y--;}}
				else if(tecla=='a'|tecla=='A'){if(x<32){}else{x--;}}
				else if(tecla=='d'|tecla=='D'){if(x>129){}else{x++;}}
				else if(tecla=='s'|tecla=='S'){if(y>34){}else{y++;}}
				else if(tecla=='m'|tecla=='M'){final++;}
				}
				
				final = mover(x,y,final,z,aleatorio,nivel);
				
				i++;
				if(i==99){
					borrarFinal(z,aleatorio);
					p = azar(num_az);
					aleatorio[0]={*p};
					aleatorio[1]={*(p+1)};
					aleatorio[2]={*(p+2)};
					aleatorio[3]={*(p+3)};
					aleatorio[4]={*(p+4)};
					nivel++;
					i=0;
					vel++;
				}
				else if(nivel==10 && i<2){
					angryBOSS_1();
				}
				else if(nivel==5 && i<2){
					angryBOSS_1();
				}
				if(final==1){
					int ans;
					ImprimeGO();
					ans = deNuevo();
					//1 = SALIR DEL JUEGO 
					//0 = REINICIAR EL JUEGO
					if(ans==1){
						
						final_global=1;	
					}
					else if(ans==0){
						final=0;
						nivel=0;
						i=0;
						vel=0;
						gotoxy(75,2);
						cout<<" "<<" "; 
					}
				}
				 				 
				
		}

	if(final_global==1){
		system("cls");
	}
	return 0;

}
