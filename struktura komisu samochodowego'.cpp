#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int n=5;
	struct Auto
	{
		string marka;
		int rocznik;
		double km;
	};
	Auto egz[100];
void menu()
{
	cout<<"+-----------------------------+\n";
	cout<<"| To jest baza komisu         |\n";
	cout<<"| samochodowego ALYTO         |\n";
	cout<<"| 1-czytaj                    |\n";
	cout<<"| 2-szukaj po marce szamochodu|\n";
	cout<<"| 3-szukaj po roczniku        |\n";
	cout<<"| 4-szukaj po przebiegu       |\n";
	cout<<"| 5-drukuj                    |\n";
	cout<<"| 6-usun                      |\n";
	cout<<"| 7-dodaj                     |\n";
	cout<<"| 8-EXIT                      |\n";
	cout<<"+-----------------------------+\n";
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void szukaj_m()
{
	cout<<"podaj marke\n";
	string odp;
	cin>>odp;
	for(int i=0; i<n; i++)
	{
		if(egz[i].marka==odp)
		{
			cout<<"samochod: "<<i+1<<" "<<egz[i].marka<<endl;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void szukaj_r()
{
	cout<<"Podaj rocznik\n";
	int odp;
	cin>>odp;
	for(int i=0; i<n; i++)
	{
		if(egz[i].rocznik<=odp)
		{
			cout<<"rocznik: "<<i+1<<" "<<egz[i].rocznik<<endl;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void szukaj_k()
{
	cout<<"Podaj przebieg\n";
	double odp;
	cin>>odp;
	for(int i=0; i<n; i++)
	{
		if(egz[i].km<=odp)
		{
			cout<<"przebieg: "<<i+1<<" "<<egz[i].km<<endl;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
int koniec()
{
	char odp;
	cout<<"zapisac zmiany t/n?\n";
	cin>>odp;
	if(odp=='t')
	{
		ofstream brajan("komis_kopia.txt");
		for(int i=0; i<5; i++)
		{
			brajan<<egz[i].marka<<" "<<egz[i].rocznik<<" "<<egz[i].km<<endl;
		}
	}
		else
			return 0;

}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void czytaj()
{
	ifstream wej("komis.txt");
	for(int i=0; i<n; i++)
	{
		wej>>egz[i].marka;
		wej>>egz[i].rocznik;
		wej>>egz[i].km;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void drukuj_All()
{
	for(int i=0; i<n; i++)
	{
		cout<<egz[i].marka<<" "<<egz[i].rocznik<<" "<<egz[i].km<<" "<<endl;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void skasuj()
{
	int odp;
	for(int i=0; i<n; i++)
	{
		cout<<"rekord nr "<<i<<" "<<egz[i].marka<<" "<<egz[i].rocznik<<" "<<egz[i].km<<" "<<endl;
	}
	cout<<"podaj numer rekord ktory chcesz usunac?\n";
	cin>>odp;
	for(int i=odp; i<n; i++)
	{
		egz[i].marka=egz[i+1].marka;
		egz[i].rocznik=egz[i+1].rocznik;
		egz[i].km=egz[i+1].km;
	}
	n--;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void dodaj()
{
	int odp;
	for(int i=0; i<n; i++)
	{
		cout<<"rekord nr "<<i<<" "<<egz[i].marka<<" "<<egz[i].rocznik<<" "<<egz[i].km<<" "<<endl;
	}
	cout<<"podaj numer rekord ktory chcesz dodaæ?\n";
	cin>>odp;
	for(int i=odp; i<n; i++)
	{
		egz[i].marka=egz[i+1].marka;
		egz[i].rocznik=egz[i+1].rocznik;
		egz[i].km=egz[i+1].km;
	}
	n++;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
main()
{
	while(true)
	{
		menu();	
		int odp;
		cin>>odp;
		switch(odp)
		{
			case 1:
				czytaj();
				break;
			case 2:
				szukaj_m();
				break;
			case 3:
				szukaj_r();
				break;
			case 4:
				szukaj_k();
				break;
			case 5:
				drukuj_All();
				break;
			case 6:
				skasuj();
				break;
			case 7:
				dodaj();
				break;
			case 8:
				koniec();
				return 0;
		}
	}
}
