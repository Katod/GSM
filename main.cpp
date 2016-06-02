#include	<stdio.h>
#include	<sqlite3.h>
#include	<stdlib.h>
#include	<string.h>
#include	<syslog.h>

const char* DB_PATH ="/home/katod/projects/Hello/build/GSM";

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
 int i;
 for(i=0; i<argc; i++){
 printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
 }
 printf("\n");
 return 0;
}


int number_verification(void *NotUsed, int argc, char **argv, char **azColName){
 int i;
 for(i=0; i<argc; i++){
 printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
 }
 printf("\n");
 return 0;
}

char* get_file(void *NotUsed, int argc, char **argv, char **azColName)
{
  return argv[1];
}



int main(int argc, char **argv){
 sqlite3 *db;
 char *zErrMsg = 0;
 int rc;

 const char *zSql = "SELECT * FROM clients";
 
 
 rc = sqlite3_open(DB_PATH, &db);
 
 if( rc ){
 fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
 sqlite3_close(db);
 //exit(1);
 }
 
 rc = sqlite3_exec(db, zSql, callback, 0, &zErrMsg);
 
 if( rc!=SQLITE_OK ){
 fprintf(stderr, "SQL error: %s\n", zErrMsg);
 sqlite3_free(zErrMsg);
 }
//  // Asterisk API
//  
//   auto	char	event[256];
//   auto	int	idx;
//  
//    // Set the syslog ident
//    openlog("mfe", LOG_PID, LOG_USER);
//  
//    // announce ourselves
//    syslog(LOG_ERR, "Starting.");
//  
//    // show how we were executed
//    idx = 0;
//    syslog(LOG_ERR, "argc = %d", argc);
//  
//    while	(idx < argc)
//    {
//      syslog(LOG_ERR, "arg[%d] = \"%s\"", idx, argv[idx]);
//      ++idx;
//    }
//    
//    
// // read events
//  while(NULL != fgets(event, sizeof(event), stdin))
//  {
//    syslog(LOG_ERR, event);
//    if('1' == *event)
//    {
//      printf("S,demo-congrats\n");
//      fflush(stdout);
//    }
//    if('2' == *event)
//    {
//      printf("S,/home/katod/Downloads/example\n");
//      fflush(stdout);
//    }
//    
//    if('3' == *event)
//    {
//      printf("S,/home/katod/Downloads/test\n");
//      fflush(stdout);
//    }
//  
//  if('#' == *event)
//  {
//    break;
//  }
//  }
//  
 sqlite3_close(db);
 return 0;
}
