#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>

using namespace std;

bool avanti = false;
int const numero = 5;
int lavcont;

struct data{
	
	int giorno;
	string mese;
	int anno;

};

struct anagrafica{
	
	string nome;
	string cognome;
	int numero_conto;
	int password;
	int saldo;
	data datanascita;
	data ap_conto;
	
	
	}ppersona[numero];

void inserire_conti(){
	int i;
	bool  continua_a_inserire;
	int continuaainserire;
	while(continua_a_inserire == false){
	
		for(i=0;i<numero;i++){
	
		cout<<"Nome persona"<<endl;
		cin>>ppersona[i].nome;
		cout<<"Cognome persona?"<<endl;
		cin>>ppersona[i].cognome;
		cout<<"Numero conto?"<<endl;
		cin>>ppersona[i].numero_conto;
		cout<<"Passward?"<<endl;
		cin>>ppersona[i].password;
		cout<<"Saldo disponibile?"<<endl;
		cin>>ppersona[i].saldo;
		cout<<"Giorno apertura conto"<<endl;
		cin>>ppersona[i].ap_conto.giorno;;
		cout<<"Mese apertura conto"<<endl;
		cin>>ppersona[i].ap_conto.mese;
		cout<<"Anno apertura conto"<<endl;
		cin>>ppersona[i].ap_conto.anno;
		cout<<"Giorno nascita"<<endl;
		cin>>ppersona[i].datanascita.giorno;
		cout<<"Mese nascita"<<endl;
		cin>>ppersona[i].datanascita.mese;
		cout<<"Anno nascita"<<endl;
		cin>>ppersona[i].datanascita.anno;
		cout<<"Inserire un altro conto?\n1-->SI\nAltro numero-->NO"<<endl;
		cin>>continuaainserire;
	
		if(continuaainserire == 1){
			continua_a_inserire = false;
		}
		else{
			continua_a_inserire = true;
			break;
		}
		}

	}
		for(int i = 0;i< numero;i++){
			cout<<ppersona[i].nome<<"\t"<<ppersona[i].cognome<<"\t"<<ppersona[i].numero_conto<<endl;
	}
	system("pause");
}

void ripetere(){
	int obb;
	cout<<"Si vuole eseguire altre azioni ?"<<endl;
	cout<<"1\tSi"<<"\n"<<"Altro numero\tNo";
	cin>>obb;
	if(obb == 1){
		avanti = false;
	}
	else{
		avanti = true;
	}
	}

void convalida_pin(){
	int i;
	int pin=0;
	int pin_c= 0;
	int tentativi  = 3;
	bool blocca=true;
	bool pin_valido = false;
	int scelta = 1;
	
	for(i=lavcont;i<lavcont+1;i++){
		pin_c = ppersona[i].password;
		while(scelta == 1){
		while(pin_valido == false ){
	
		if(tentativi == 3){
		cout<<"Mancano 3 tentativi"<<endl;
		}
		if(tentativi == 2){
		cout<<"Mancano 2 tentativi"<<endl;
		}
		if(tentativi == 1){
		cout<<"Ultimo tentativo"<<endl;
			}
		if(tentativi <= 0){
			blocca = false;
			}
		if(blocca == false ){
			cout<<"Bancomat bloccato "<<endl;
			pin = 00000;
		}
		cout<<"Inserisci Pin";
		cin>>pin_c;
		if( pin_c == ppersona[i].password){
			system("cls");
			pin_c = ppersona[i].password;
			cout<<"Inserisci nuovamente pin";
			cin>>pin_c;
			if(ppersona[i].password== pin_c){
				pin_valido=true;
			}
			else{
				pin_valido=false;
				cout<<"Pin errato"<<endl;
				tentativi--;
			}
		}
		else{
			cout<<"Pin errato"<<endl;
			tentativi--;
		}
		if(tentativi <= 0 ){
			cout<<"Vuoi continuare ? "<<endl;
			cout<<"Si\t1\t\tNo\t0"<<endl;
			cin>>scelta;
			if(scelta == 0){
					exit(EXIT_SUCCESS);
			}
		}	
		}	
		scelta = 0;
		system("cls");
		cout<<"Pin inserito correttamente"<<endl;
		}
	}
	
}

void commissione(){
	int commissione=3;
	int i;
	cout<<"Per eseguire l'operazione e' stata sottratta al suo conto una commissione\n";
	for(i=lavcont;i<numero;i++){
		ppersona[i].saldo=ppersona[i].saldo-commissione;
	}
	
}

void prelievo(){
	int i;
	convalida_pin();
	float prelievo;
	
	bool prelievo_valido = false;
	commissione();
	for(i=lavcont;i<numero;i++){
		while(prelievo_valido == false){
		cout<<"Quanto si desidera prelevare"<<endl;
		cin>>prelievo;
	
	if(prelievo > ppersona[i].saldo){
		cout<<"Saldo non disponibile"<<endl;
		prelievo_valido = false;
	}
	else{
		cout<<"Prelievo eseguito con successo"<<endl;
		ppersona[i].saldo = ppersona[i].saldo - prelievo;
		cout<<"Saldo disponibile "<< ppersona[i].saldo<<endl;
		prelievo_valido = true;		
	}	
	}
	
	
	}
	ripetere();
	}
	
void versamento(){
	convalida_pin();
	int i;
	float versamento;
	commissione();
	for(i = lavcont; i < numero;i++){
		cout<<"Quanto si vuole versare"<<endl;
		cin>>versamento;
		ppersona[i].saldo = ppersona[i].saldo + versamento;
		cout<<"Saldo ora disponibile-->"<<ppersona[i].saldo<<endl;
		break;
		
	}
	ripetere();
	
}

void mostra_conto(){
	int i;
	for(i=lavcont;i<numero;i++){
	cout<<ppersona[i].nome<<"---"<<ppersona[i].cognome<<endl;
	cout<<"Saldo disponibile"<<endl;
	cout<<ppersona[i].saldo<<endl;
	cout<<"Data nascita"<<endl;
	cout<<ppersona[i].datanascita.giorno<<"/"<<ppersona[i].datanascita.mese<<"/"<<ppersona[i].datanascita.anno<<endl;
	cout<<"Data apertura conto"<<endl;
	cout<<ppersona[i].ap_conto.giorno<<"/"<<ppersona[i].ap_conto.mese<<"/"<<ppersona[i].ap_conto.anno<<endl;
	break;	
	}
	ripetere();
	}

void inserireconti(){
	int i;
	int convpassword_master;
	bool lavorareconto;
	int convalidaconto;
	int passwordcont;
	int cont_conti;
	int password_master = 2580;
	cout<<"Password_master"<<endl;
	cin>>convpassword_master;

	if(convpassword_master == password_master){
		inserire_conti();
		cont_conti++;
	}
	else{
		cout<<"Password master non corretta"<<endl;
		system("pause");
		exit(EXIT_SUCCESS);
		;
	}
	
	while(lavorareconto == false){
		cout<<"con quale conto si vuole agire?";
		cin>>convalidaconto;
	
		for(i=0;i<numero;i++){
			if(convalidaconto == ppersona[i].numero_conto){
			cout<<"inserire password"<<endl;
			cin>>passwordcont;
				if(passwordcont == ppersona[i].password){
					lavorareconto = true;
					lavcont = i;
				}
				else{
					cout<<"conto non valido"<<endl;
					cout<<"riprovare"<<endl;
			}
		}
				else{
					cout<<"conto non esistente riprovare"<<endl;
		}	
	}	
	}
}

void scegli_conto(){
		int i;
		int convpassword_master;
		bool lavorareconto=false;
		int convalidaconto;
		int passwordcont;
		
		while(lavorareconto == false){
		cout<<"con quale conto si vuole agire?";
		cin>>convalidaconto;
	
		for(i=0;i<numero;i++){
			if(convalidaconto == ppersona[i].numero_conto){
					lavorareconto = true;
					lavcont = i;
				}
			else{
					cout<<"Conto non esistente"<<endl;
						exit(EXIT_SUCCESS);
		}	
	}	
	}
	
}

void menu(){
	int i;
	int scelta = 5;
	
	for(i=0;i<numero;i++){
		while (avanti == false){
		system("cls");
		cout<<"Buongiorno"<<endl;
		cout<<"Cosa si intende eseguire"<<endl;
	
		cout<<"Prelievo\t\t1"<<endl;
		cout<<"Versamento\t\t2"<<endl;
		cout<<"Mostra conto\t\t3"<<endl;
		cout<<"Inserire conti\t\t4"<<endl;
		cout<<"Scegliere conti\t\t5"<<endl;
		cout<<"Esci dal programma\t0"<<endl;
		cin>>scelta;
	
		switch  (scelta)
		{
			case 0 :{
				exit(EXIT_SUCCESS);
			}			
			case 1 :{
				prelievo();
				break;
			}
			case 2:{
				versamento();
				break;
			}
			case 3:{
				mostra_conto();
				break;
			}
			case 4:{
				inserireconti();
				break;
			}
			case 5:{
				scegli_conto();
				break;
			}	
		}	
		}
	}
}

main(){	
	menu();
}


//fare la storia degli interessi
