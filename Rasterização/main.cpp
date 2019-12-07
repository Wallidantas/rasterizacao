#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Wallisson Dantas da Silva - 11321924


int x1,x2;  // Declaração das variaveis
int Y1,Y2;
int dx,dy;

clock_t temp_init_reta,temp_fim_reta;
clock_t temp_init_bresenham,temp_fim_bresenham;   // declaração das funções para gerar o tempo de cada algoritmo
clock_t temp_init_dda,temp_fim_dda;
clock_t temp_init_opengl,temp_fim_opengl;

void reta(){                              // equação da reta
temp_init_reta = clock();                // inicia a contagem do tempo

    for(int s = 1; s < 100; s++){          // um for para fazer N iterações
        int x=x1;
        float m,y;
        m=(float)dy/dx;                  // calculo do M delta y sobre delta x


        glBegin(GL_POINTS);              // parametros para gerar os pontos
        glColor3d(1,1,1);                // cor da ponto - Branco
        glVertex2d(x,y+10);              // posição inicial e final adicionado + 10 para o deslocamento para não ficar uma por cima da outra

        for(int x =x1; x<x2; x++){        // equação da reta conforme estudado em sala
            y = round(m*(x-x1)+ Y1);
            glVertex2d(x,y+10);
        }
        glEnd();                               //Fim da funçao que gera os pontos
        glFlush();
    }
temp_fim_reta = clock();                      // termina a contagem do tempo // proxima linha printa o tempo na tela
printf("\nTempo da eq da reta: %4.0f ms\n",1000*(double)(temp_fim_reta-temp_init_reta)/(double)(CLOCKS_PER_SEC));
}

void bresenham(){                           //função do bresenham
    temp_init_bresenham = clock();          // inicia a contagem do tempo
    for(int s = 1; s < 100; s++){           // // um for para fazer N iterações
        int p, x, y;

        x= x1;
        y= Y1;

        p =( 2*dx)-dy;                      // função para encontrar o P

        glBegin(GL_POINTS);                 // parametros para gerar os pontos
        glColor3d(0,1,0);                   // cor da ponto - verde
        glVertex2d(x,y+20);                 // posição inicial e final adicionado + 20 para o deslocamento para não ficar uma por cima da outra

        for( int i = x1; i < x2; i++){       // equação de bresenham estudada em sala e passada para o codigo
                if(p>=0){                    // para quando o P é maior ou igual a zero
                x++;
                y++;
                p= p+(2*dy) - 2*dx;
                glVertex2d(x,y+20);
                }
                else if( p<0 ){             // para quando o P é menor que zero
                x ++;                       // nao é incrementado o Y.
                p =  p +( 2*dy );
                glVertex2d(x,y+20);
                }
}
    glEnd();                               //Fim da funçao que gera os pontos
    glFlush();
    }
temp_fim_bresenham = clock();              // termina a contagem do tempo // proxima linha printa o tempo na tela
printf("\nTempo da reta de Bresenham: %4.0f ms\n",1000*(double)(temp_fim_bresenham-temp_init_bresenham)/(double)(CLOCKS_PER_SEC));

}

void dda(){                                // função DDA
temp_init_dda = clock();                   // inicia a contagem do tempo

 for(int s = 1; s < 100; s++){             // um for para fazer N iterações
        int dx=x2-x1, dy=Y2-Y1;            // declaração de variaveis
        float y=Y1,m;
        m =(float) dy/dx;                 // calculo do M

        glBegin(GL_POINTS);                 // parametros para gerar os pontos
        glColor3d(1,0,0);                   // cor da ponto - Vermelha
        glVertex2d(x1,Y1);                  //posição inicial e final sem adicionar + 10

        for(int x=x1; x<=x2;x++){          // implementação do algoritmo do DDA
            x++;                           // onde sempre acrescentamos +1 no x
            y=Y1+m;                        // o no y sempre pegamos o y inicial mais o valor do M
            glVertex2d(round(x),round(y));
        }

        glEnd();                               //Fim da fun��o que gera os pontos
        glFlush();
}
temp_fim_dda = clock();                       // termina a contagem do tempo // proxima linha printa o tempo na tela
printf("\nTempo da reta de DDA: %4.0f ms\n",1000*(double)(temp_fim_dda-temp_init_dda)/(double)(CLOCKS_PER_SEC));
}

void opengl(){                               // função nativa openGL bresenham
    temp_init_opengl = clock();             // inicia a contagem do tempo

    for(int s = 1; s < 100; s++){           // um for para fazer N iterações
        glBegin(GL_LINES);                  // aqui ele vai gerar uma linha reta em vez de pontos.
        glColor3d (0, 0, 1);                //Cor da linha - azul
        glVertex2d(x1,Y1+30);               //posição inicial e final adicionado + 30 para o deslocamento para não ficar uma por cima da outra
        glVertex2d(x2,Y2+30);
        glEnd ();                           //Fim da funçao que gera os pontos
        glFlush();
    }
    temp_fim_opengl = clock();               // termina a contagem do tempo // proxima linha printa o tempo na tela
printf("\nTempo de bresenham - Eq da reta openGL: %4.0f ms\n",1000*(double)(temp_fim_opengl-temp_init_opengl)/(double)(CLOCKS_PER_SEC));
}
void display(void)                                //funçao que gera os pontos na tela
{
    glClearColor(0.0, 0.0, 0.0, 0.0);         //Limpando a tela
    glClear(GL_COLOR_BUFFER_BIT);             //Limpando o buffer
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 600.0, 0, 600.0);        //indicando que quer usar o glu em 2d

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

        reta();                        // chamando as funções para a tela

        dda();

        bresenham();

        opengl();

    glEnd();                               //Fim da fun��o que gera os pontos
glFlush();                             //descarga
}
void entrada(){                               //função de entrada para printar as informações
    printf(" \tAluno : Wallisson Dantas da Silva\n");
    printf(" \tMatricula : 11321924\n");
    printf(" \tDisciplina - Computacao Grafica\n");
    printf(" \tAlgoritmos - EQ DA RETA / DDA / BRESENHAM / BRESENHAM OPENGL\n");
    printf(" \tProcessador: I5-7300HQ - 2.50 GHz\n\n");
    printf(" \tTEMPOS:\n");

    x1=  0;            // pontos escolhidos podendo ser alterados por aqui
    Y1=  0;
    x2= 300;
    Y2= 300;
}

int main (int argc,char **argv)
{
    entrada();     //chamada da função na main

    dx = x2 - x1;   //calculo dos deltas
    dy = Y2 - Y1;


    glutInit(&argc,argv);    //inicia o GLUT
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);  //Define modo de exibiçao
    glutInitWindowPosition(0,0);             //Posiçao da janela na area do monitor
    glutInitWindowSize(800,800);                 //tamanho da janela grafica
    glutCreateWindow("Algoritmos de rasterizacao - Wallisson Dantas"); // Titulo da janela

    glutDisplayFunc(display);                   //processamento da cena

    glutMainLoop();

return 0;
}
