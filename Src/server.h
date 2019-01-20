#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#include <netdb.h>
#include <arpa/inet.h>

#define NBCARTES 13
#define NBJOUEURS 4
#define NBOBJETS 8
#define AVOIR_CARTE(nbcarte) (nbcarte > 0 ? 100 : 0)

struct _client {
    char ipAddress[40];
    int port;
    char name[40];
} tcpClients[NBJOUEURS];
int nbClients;
int fsmServer;
int deck[NBCARTES]={0,1,2,3,4,5,6,7,8,9,10,11,12};
int tableCartes[NBJOUEURS][NBOBJETS];
char *nomcartes[]= {"Sebastian Moran", "irene Adler", "inspector Lestrade",
  	"inspector Gregson", "inspector Baynes", "inspector Bradstreet",
  	"inspector Hopkins", "Sherlock Holmes", "John Watson", "Mycroft Holmes",
  	"Mrs. Hudson", "Mary Morstan", "James Moriarty"};
int joueurCourant;
char joueurPerdant;
int nbPerdant;