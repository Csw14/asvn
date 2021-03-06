#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
<<<<<<< HEAD
#include <sys/stat.h>////////////////////////////
#include <fcntl.h>
#include <pwd.h>/////////////////////////
#include <netinet/in.h>
#include <time.h>
#include <dirent.h>///////////////////////////
=======
#include <sys/stat.h>
#include <fcntl.h>
#include <pwd.h>
#include <netinet/in.h>
#include <time.h>
#include <dirent.h>
>>>>>>> 33323cd91f55531a356d55360d6b0c002bff47d5

#ifndef BSIZE
  #define BSIZE 1024
#endif

typedef struct Port
{
  int p1;
  int p2;
} Port;

typedef struct State
{
  /* Connection mode: NORMAL, SERVER, CLIENT */
  int mode;

  /* Is user loggd in? */
  int logged_in;

  /* Is this username allowed? */
  int username_ok;
  char *username;
  
  /* Response message to client e.g. 220 Welcome */
  char *message;

  /* Commander connection */
  int connection;

  /* Socket for passive connection (must be accepted later) */
  int sock_pasv;

  /* Transfer process id */
  int tr_pid;

} State;


/* Command struct */
typedef struct Command
{
  char command[5];
  char arg[BSIZE];
} Command;

/**
 * Connection mode
 * NORMAL - normal connection mode, nothing to transfer
 * SERVER - passive connection (PASV command), server listens
 * CLIENT - server connects to client (PORT command)
 */
typedef enum conn_mode{ NORMAL, SERVER, CLIENT }conn_mode;

/* Commands enumeration */
typedef enum cmdlist 
{ 
  ABOR, CWD, DELE, LIST, MDTM, MKD, NLST, PASS, PASV,
  PORT, PWD, QUIT, RETR, RMD, RNFR, RNTO, SITE, SIZE,
<<<<<<< HEAD
  STOR, TYPE, USER, NOOP, CRET
=======
  STOR, TYPE, USER, NOOP
<<<<<<< HEAD
} cmdlist;//RMD, RNFR, RNTO, SITE, SIZE,STOR, TYPE, USER, NOOP
  

/* String mappings for cmdlist *///주소의 배열로 저장하니 주솟값으로 저장이 되어있을 듯 
=======
>>>>>>> cf00542ea63e11eea887dee854807a20cdb33349
} cmdlist;

/* String mappings for cmdlist */
>>>>>>> 33323cd91f55531a356d55360d6b0c002bff47d5
static const char *cmdlist_str[] = 
{
  "ABOR", "CWD", "DELE", "LIST", "MDTM", "MKD", "NLST", "PASS", "PASV",
  "PORT", "PWD", "QUIT", "RETR", "RMD", "RNFR", "RNTO", "SITE", "SIZE",
  "STOR", "TYPE", "USER", "NOOP", "CRET"
};

/* Valid usernames for anonymous ftp */
static const char *usernames[] = 
{
  "ftp","anonymous","public","anon","test","foo","siim"
};

/* Welcome message */
static char *welcome_message = "A very warm welcome!";

/* Server functions */
void gen_port(Port *);
void parse_command(char *, Command *);
int create_socket(int port);
void write_state(State *);
int accept_connection(int);

/* Commands handle functions*/
void response(Command *, State *);
void ftp_user(Command *, State *);
void ftp_pass(Command *, State *);
void ftp_pwd(Command *, State *);
void ftp_cwd(Command *, State *);
void ftp_mkd(Command *, State *);
void ftp_rmd(Command *, State *);
void ftp_pasv(Command *, State *);
void ftp_list(Command *, State *);
void ftp_retr(Command *, State *);
void ftp_stor(Command *, State *);
void ftp_dele(Command *, State *);
void ftp_size(Command *, State *);
void ftp_quit(State *);
void ftp_type(Command *, State *);
void ftp_abor(State *);

void str_perm(int, char *);
void my_wait(int);
<<<<<<< HEAD
=======

void dir_mk(char* dname);
void hs_cret(Command *, State *);
>>>>>>> 33323cd91f55531a356d55360d6b0c002bff47d5
