
..
#include<iostream>
#include<cmath>
#include<fstream>
#include<windows.h>
using namespace std;
//presentation 
void center(int n)
{
    int i;
    for(i=0;i<n;i++)printf(" ");
}
void presentation()
{ int i;
    for(i=0;i<20;i++)cout<<"\n\n\n";
    {

    center(40);cout<<" |||      |||      ||||    ||||  \n";Sleep(500);
    center(40);cout<<" |||     || ||     ||| |  | |||  \n";Sleep(500);
    center(40);cout<<" |||    ||___||    |||  ||  |||  \n";Sleep(500);
    center(40);cout<<" |||    ||   ||    |||      |||  \n";Sleep(500);
    center(40);cout<<" |||    ||   ||    |||      |||  \n\n";Sleep(500);
    center(39);cout<<"Institut   Africain   de   Mananagement";Sleep(500);
    cout<<"\n\n";
    cout<<"\t\t\t*******************************************************\n";Sleep(500);
    cout<<"\t\t\t*                                                     *\n";Sleep(500);
    cout<<"\t\t\t*          PROGRAMME D'ANALYSE STATISTIQUE            *\n";Sleep(500);
    cout<<"\t\t\t*                                                     *\n";Sleep(500);
    cout<<"\t\t\t*******************************************************\n";Sleep(500);
    cout<<"\t        Presente par                                         \n";Sleep(500);
    cout<<"\tKenzo GIRARD                                                      Sous la supervision de               \n";Sleep(500);
    cout<<"\tMamadou Alioune GUEYE                                                 Dr. Fode CAMARA             \n";Sleep(500);
    cout<<"\tKhadidiatou DIA                                                                     \n";Sleep(500);
    cout<<"\tMariama POUYE                                                                    \n";Sleep(500);
    cout<<"\tTherese Wittal NDIONE                                                                    \n";Sleep(500);
    cout<<"\t\t                                                    \n";for(i=0;i<3;i++){ cout<<"\n",Sleep(200);}	}
    for(i=0;i<2;i++)Sleep(200);system("color A");Sleep(200);}



float *SaisieSerie(float *t, int n){
    cout <<"Saisissez votre serie statistique" <<endl;

	int i;
	t = new float[n];
	for(i=0;i<n;i++){
		cout <<"Donner t"<<"["<<i+1<<"] :";
		cin>>t[i];
	}

	return t;
}
void AfficheSerie(float *t, int n){
    cout <<"Votre serie statistique" <<endl;

	int i;
	for(i=0;i<n;i++){		
		cout<<t[i]<<"     ";
	}
	cout <<endl;
}
float moyenne (float *t, int n){
	float mean=0;
	int i;
	for(i=0;i<n;i++){
		mean+=t[i];
	}
	mean=mean/n;
	return mean;
}
float variance (float *t,int n){
	float mean,somme_e=0.0,vrc;
	mean=moyenne(t,n);
	for(int i=0;i<n;i++)
		somme_e +=pow(t[i]-mean,2);
	vrc=somme_e/n;
	return vrc;
}
float ecart_type (float *t,int n){
	float ecartype,vrc;
	vrc=variance(t,n);
	ecartype = sqrt(vrc);
	return ecartype;
}
float *tricroissant(float *t,int n)
{
    int i,index,j;
    float tmp=0;

     for (i=0; i < (n-1); i++){
    index = i;

    for (j=i + 1; j < n; j++)
    {
      if (t[index] > t[j])
        index = j;
    }
    if (index != i)
    {
      tmp = t[i];
      t[i] = t[index];
      t[index] = tmp;
    }
  }
  return t;
}
float mediane(float *t,int n){
	float mediane;
	int index;
	t=tricroissant(t,n);
	if (n%2==0)
	{
		index=n/2;
		mediane=(t[index]+t[index-1])/2;
	}
	else{
		index=(n/2)+1;
		mediane=t[index];

	}
return mediane;
}

float **frequence(float *t,int n,int &l_tf){
    float *t_f = new float[n];
    int i_tf=0,found=0,nf=0;

	for(int i=0;i<n;i++){
	    found=0;
	    for(int j=0;j<n;j++){
	        if(t[i]==t_f[j]){
	            found = 1;
	            break;
	        }
	    }
	    if(found==0){
	       t_f[i_tf] = t[i];
	       i_tf++;
	    }
	}

    float ** freq = new float*[2];
    // dynamically allocate memory of size `N` for each row
    for (int i = 0; i < 2; i++) {
        freq[i] = new float[i_tf];
    }

	    for(int j=0;j<i_tf;j++){ //j parcour colonne
	       nf=0;
	       freq[0][j] = t_f[j];
	       for(int k=0;k<n;k++){
	           if(t_f[j]==t[k]){
	               nf++;
	           }
	       }
	       freq[1][j] = nf;
	    }
	l_tf = i_tf;
	return freq;
}

float mode(float *t,int n,int l_tf){
    float md;
    float **freq = frequence(t,n,l_tf);
    int max = 0,idC;

    for(int i=0; i<l_tf;i++){ //i parcour colonne
        if(freq[1][i]>=max){

            max = freq[1][i];
            idC = i; //indice de la colonne qui contient le maximum
        }
    }

    md = freq[0][idC];
    return md;
}

float _quartOne(float *t,int n){
    t=tricroissant(t,n);
    float lQ,Q;
    int x;

    lQ = 0.25 *n;
    x = ceil(lQ);
    Q = t[x-1];

    return Q;
}

float _quarThree(float *t,int n){
    t=tricroissant(t,n);
    float lQ,Q;
    int x;

    lQ = 0.75 *n;
    x = ceil(lQ);
    Q = t[x-1];

    return Q;
}

// fonction bivariee
float **ecritureSerie_biv(float **data,int n){

    data = new float*[2];
    for (int i = 0; i < 2; i++) {
        data[i] = new float[n];
    }

    for(int i=0;i<2;i++){
        if(i==0){
            cout<<"SerieX: "<<endl;
        }
        if(i==1){
            cout<<"SerieY: "<<endl;
        }
        for(int j=0;j<n;j++){
            cout <<"Donner data"<<"["<<i+1<<"]"<<"["<<j+1<<"]: ";
		    cin>>data[i][j];
        }
        cout<<endl;
	}

     return data;
}

void AfficheMatrix(float **data,int n){
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
             cout<<"|     "<<data[i][j];
        }
        cout<<endl;
    }
}

float covariance(float **data,int n){
    float mX =0, mY =0;
    float c=0;
    float cov;

    mX = moyenne(data[0],n);
    mY = moyenne(data[1],n);

        for(int j=0;j<n;j++){
            c += (data[0][j]-mX)*(data[1][j]-mY);
        }

     cov = c/(n-1);

     return cov;
}

	int main(){
		
		int choix;
		int n,l_tf=0;
		float *t;
		float **freq;
		float **data;
		float mean;
		
		presentation();
		
			center(20);cout<<"Chargement du programme en cours";for(int i=0;i<5;i++){Sleep(500);cout<<".";
		    system("cls");}
		do{	
			cout<<"BIENVENUE DANS LE MENU PRINCIPALE\n\n";
			cout<<"Veuillez entrer un chiffre pour effectuer votre demande\n";
			cout<<"\t\n1-Analyse unitaire  \n";//MENU PRINCIPAL
			cout<<"\t2-Analyse bivariee \n"; 
			cout<<"\t\t3-Quitter \n\n";
			cout<<"\t\tEntrer votre choix : ";
			cin>>choix;
			 	system("cls");
			
		
			switch(choix)
			{
					case 1 :
					{
				
						cout<<"Entrez la taille totale de votre serie: ";
						   	cin>>n;
						   	t=SaisieSerie(t,n);
						   	AfficheSerie(t,n);
				 		cout<<"\t-la Moyenne de votre serie est : "<<moyenne(t,n)<<endl;
				  		cout<<"\t-la Variance de votre serie est : "<<variance(t,n)<<endl;
				  		cout<<"\t-l'Ecart type de votre serie est : "<<ecart_type(t,n)<<endl;
				  		cout<<"\t-la Mediane de votre serie est : "<<mediane(t,n)<<endl;
				  		
				  		cout<<"\t-la Frequence de votre serie est : "<<frequence(t,n,l_tf);
				  		/*freq = frequence(t,n,l_tf);
			            	// afficher matrix
                    	 	cout <<endl;
                    	        for(int i=0;i<2;i++)
								{
                    	        	for(int j=0;j<l_tf;j++)
									{
                    	            	cout<<" "<<freq[i][j];  
									}
									cout<<endl;
                    	        }*/
                  		cout<<"\t-le mode de votre serie est : "<<mode(t,n,l_tf)<<endl;
                		cout<<"\t-le premier quartile de votre serie est : "<<_quartOne(t,n)<<endl;
                  		cout<<"\t-le troisieme quartile de votre serie est : "<<_quarThree(t,n)<<endl;
                 
									//export analyse_univarié.txt analyse_univarié.csv analyse_univarié.doc
										fstream file("Analyse_univariée.txt",ios::out|ios::trunc); 
 										fstream file1("Analyse_univariée.csv",ios::out|ios::trunc);
										fstream file2("Analyse_univariée.doc",ios::out|ios::trunc);
						if (file.is_open())
						{ 
							//file analyse_univarié.txt
								file<<"Moyenne: "<<moyenne(t,n)<<endl;
								file<<"Variance: "<<variance(t,n)<<endl;
								file<<"Ecart-type: "<<ecart_type(t,n)<<endl;
								file<<"Mediane: "<<mediane(t,n)<<endl;
								file<<"Frequence: "<<frequence(t,n,l_tf)<<endl;
								file<<"Mode: "<<mode(t,n,l_tf)<<endl;
								file<<"Quartile 1: "<<_quartOne(t,n)<<endl;
								file<<"Quartile 3: "<<_quarThree(t,n)<<endl;
		
								//file1 analyse_univarié.csv
									file1<<"Moyenne: "<<moyenne(t,n)<<endl;
									file1<<"Variance: "<<variance(t,n)<<endl;
									file1<<"Ecart-type: "<<ecart_type(t,n)<<endl;
									file1<<"Mediane: "<<mediane(t,n)<<endl;
									file1<<"Frequence: "<<frequence(t,n,l_tf)<<endl;
									file1<<"Mode: "<<mode(t,n,l_tf)<<endl;
									file1<<"Quartile 1: "<<_quartOne(t,n)<<endl;
									file1<<"Quartile 3: "<<_quarThree(t,n)<<endl;
									
										//file2 analyse_univarié.doc
											file2<<"Moyenne: "<<moyenne(t,n)<<endl;
											file2<<"Variance: "<<variance(t,n)<<endl;
											file2<<"Ecart-type: "<<ecart_type(t,n)<<endl;
											file2<<"Mediane: "<<mediane(t,n)<<endl;
											file2<<"Frequence: "<<frequence(t,n,l_tf)<<endl;
											file2<<"Mode: "<<mode(t,n,l_tf)<<endl;
											file2<<"Quartile 1: "<<_quartOne(t,n)<<endl;
											file2<<"Quartile 3: "<<_quarThree(t,n)<<endl;
							file.close();
								file1.close();
										file2.close();
			
							cout<<"\n Fichier creer et donnees enregistrer avec succes"<<endl;
						}
						else
							{
								cout<<"Erreur d'enregistrement des donnees"<<endl;
							}
					break;
					}

				case 2:
						{
							cout<<"Entrez la taille totale de votre serie: ";
				 		  	cin>>n;

				   			data = ecritureSerie_biv(data,n);
				   			AfficheMatrix(data,n);
				  			cout<<"la covariance de votre serie est: "<<covariance(data,n)<<endl; 
						
								//Export analyse_bivariee.txt
								fstream file3("Analyse_bivariee.txt",ios::out|ios::trunc);
								if (file3.is_open())
							{ 
	
								file3<<"Covariance: "<<covariance(data,n);
								file3.close();
								cout<<"\n fichier creer et donnees enregistrer avec succes"<<endl;
							}
							else
							{
								cout<<"erreur d'enregistrement des donnees"<<endl;
							}
						break;
						}
	
		
				
					}
			
			}while(choix!=3);
			    cout<<"\n\n\n";
				cout<<"\t\t\t*****************************************";
				cout<<"\n\t\t\t* Au revoir, Nous vous remercions !!!!! *\n";
				cout<<"\t\t\t*****************************************";
				}
		

			



