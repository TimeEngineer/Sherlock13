#include <SDL.h>     
#include <SDL_image.h>        
#include <SDL_ttf.h>        
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define NBJOUEURS 4
#define NBOBJETS 8

pthread_t thread_serveur_tcp_id;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
char gbuffer[256];
char gServerIpAddress[256];
int gServerPort;
char gClientIpAddress[256];
int gClientPort;
char gName[256];
char gNames[NBJOUEURS][256];
int gId;
int joueurSel;
int objetSel;
int guiltSel;
int guiltGuess[13];
int tableCartes[NBJOUEURS][NBOBJETS];
int b[3];
int goEnabled;
int connectEnabled;

char *nbobjets[]={"5","5","5","5","4","3","3","3"};
char *nbnoms[]={"Sebastian Moran", "irene Adler", "inspector Lestrade",
  	"inspector Gregson", "inspector Baynes", "inspector Bradstreet",
 	"inspector Hopkins", "Sherlock Holmes", "John Watson", "Mycroft Holmes",
  	"Mrs. Hudson", "Mary Morstan", "James Moriarty"};

volatile int synchro;