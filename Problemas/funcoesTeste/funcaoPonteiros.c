//explicacao de ponteiros durante a aula.


//exemplo de soma de ponteiros:

int *p; int v[10];

p = &v[0];

//v[0] pod ser acessado por *p ou v[0]
//v[i] pode ser acessado por *(p+i) ou v[i]
//v[i] e o mesmo que *(v+i) e &v[i] e o mesmo que p+i

//exemplo de subtracao de ponteiros:

int *p; int *q;

//p = &v[k];
//q = &v[i]
//p - q = k - i;


//exemplo  de funcao que percore um vetor com ponteiros:

double vetor_average(int v[], int n){
    int *p;
    double sum = 0.0;

    for(p = v; p < v + n; p++){
        sum += *p;
    }
    return sum/n;
}