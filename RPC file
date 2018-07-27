# RPC
Remote Procedural Call
Factorial program using RPC

fact.x
<pre>
struct val 
{
 int a;
};

program FACT_PROG 
{
 version FACT_VERS 
 {
  int FACT(val) = 1;
 } = 1;

} = 0x23451115;

</pre>
run a command: <i>rpcgen -a -C fact.x</i>
now edit fact_server.c

<pre>
#include "fact.h"

int *
fact_1_svc(val *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */
	
	int i,n,fact=1;
	n=argp->a;
	for(i=1;i<=n;i++){
		fact=fact*i;
	}
	 result=fact;
	return &result;
}
</pre>
now edit fact_client.c

<pre>
#include "fact.h"

void
fact_prog_1(char *host)
{
	CLIENT *clnt;
	int  *result_1;
	val  fact_1_arg;
	int x;
	
#ifndef	DEBUG
	clnt = clnt_create (host, FACT_PROG, FACT_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	
	printf("ENter a value:");
	scanf("%d",&x);
	fact_1_arg.a=x;
	
	result_1 = fact_1(&fact_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else{
		printf("factorial : %d",*result_1);
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	fact_prog_1 (host);
exit (0);
}
</pre>
save and run a command : <i>make -f Makefile.fact</i>

now run <i> ./fact_server </i>in one terminal
and run <i> ./fact_client </i>in another terminal
