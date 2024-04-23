# Shell lab

## 实验总结

整体来说还是比较轻松的，第八章很大的篇幅都可以用在这个实验上，并且实验给的Hint也足够详细 。

但是感觉这个实验的阶梯性并没有设计的很好，读完第八章之后写出来的简易代码，存在一次性能过很多个trace，或者前面后面trace都能过，但是中间的过不了的现象。

## **前言**

在做shelllab之前，请确保已经熟读了第八章，shelllab的很多内容都是课本上原原本本的代码。如果第八章看的不仔细，这个lab很难完成。

**在熟读第八章的基础上，writeup文件中的Hints部分对做实验非常有帮助。**

## **实验介绍**

![](https://cdn.nlark.com/yuque/0/2024/webp/25607809/1708742620686-4b3384dc-c0e7-4965-a2e3-cd7dcb1a70f2.webp#averageHue=%232c3037&clientId=u2c46e135-e44f-4&from=paste&id=u7a878eda&originHeight=679&originWidth=1003&originalType=url&ratio=1.25&rotation=0&showTitle=false&status=done&style=none&taskId=uccce0dcf-813a-45b2-b2d9-6b187cfd0c9&title=)

实验的目录如图所示:

1. tsh.c是tsh的源文件，本实验的过程就是根据trace文件的提示，在tsh.c中编写一些函数，实现tsh的一些功能。
2. Makefile可以编译我们tsh.c，生成对应的二进制文件tsh，同时也可以用于测试我们的tsh功能，下文会介绍。
3. myxxx.c，sdriver.pl 是用于测试我们tsh的文件。
4. tshref是老师写好的一个tsh，只要我们的程序的行为跟老师的tsh程序行为一致，就算我们通关了。同时也可·················以用tshref运行trace文件，得到本次trace的正常输出应该是什么。
5. 如果不想运行，可以直接查看tshref.out文件来获得本次trace的正常输出。
6. trace文件比较多，为了显示比较好看，被我过滤掉了。trace中会有提示，指引你下一步应该实现什么功能。

![](https://cdn.nlark.com/yuque/0/2024/webp/25607809/1708742620703-66ae66f4-35f9-4ad5-b654-12cb00b8a3d2.webp#averageHue=%232f323a&clientId=u2c46e135-e44f-4&from=paste&id=u04751e91&originHeight=679&originWidth=1003&originalType=url&ratio=1.25&rotation=0&showTitle=false&status=done&style=none&taskId=ue484641e-7b4d-4127-9c46-6126ca3ff47&title=)
在编译完成(make)tsh.c后，可以通过make test01来进行第一个测试。同时，我们也可以运行make rtest01 来了解功能正常的tsh运行此测试文件应该会产生什么样的输入。本实验共有16个trace文件，只要我们16个文件产生的输出与tshref都相同，就算成功。

---

对shell比较熟悉的同学或许有好点子来与tshref做比较，比如采用如下命令：

```bash
diff <(make rtest01) <(make test01)
```
将rtest放在前面仅仅是因为在我的shell中， diff的第一个输入如果与第二个不同，会产生一个红色的输出，比较醒目。这样看到单独的红色输出就知道自己可能错了。
这其实是个冷知识，叫做进程替换(_process substitution)：_<( Command )会执行Command并将结果输出到一个临时文件中，并将<( Command )替换成临时文件名。
![](https://cdn.nlark.com/yuque/0/2024/webp/25607809/1708742620731-8b9b21b2-fcf9-4227-bbdc-39808f26a600.webp#averageHue=%232b2e36&clientId=u2c46e135-e44f-4&from=paste&id=u91760a6b&originHeight=679&originWidth=1003&originalType=url&ratio=1.25&rotation=0&showTitle=false&status=done&style=none&taskId=u4b1f9d65-4890-4eca-885c-831414b9736&title=)
可以看到我们与标准的tsh产生的输出只有名字不一样而已，证明我们通过了这个测试。
## **trace01(Properly terminate on EOF.)**
skip这个trace，-.-，发现刚下载完没有编写的tsh.c都可以通过这个测试。
## **trace02(trace02.txt - Process builtin quit command.)**
这个trace让我们实现内置的quit命令。
首先，我们需要编写eval()函数，此函数的**部分作用**是区分命令是否是内置命令，如果是内置命令，就调用builtin_cmd()函数，通过此函数来执行内置命令。
这两个函数都在在课本的8.4.6节有介绍，我们只需要找到tsh.c中的eval(), 与builtin_cmd()，然后抄上去就可以了。
![](https://cdn.nlark.com/yuque/0/2024/webp/25607809/1708742620686-3a4b35e4-6c71-4f4e-ad0e-2ae6b5994ce3.webp#averageHue=%23fbfafa&clientId=u2c46e135-e44f-4&from=paste&id=u0779791f&originHeight=753&originWidth=634&originalType=url&ratio=1.25&rotation=0&showTitle=false&status=done&style=none&taskId=u71e2069e-39cf-42dd-a1ff-e45cdfb3e33&title=)
抄写完成后，通过运行我们前面介绍的测试命令，来测试这个trace。(编写完成后，不要忘记再次make一下编译tsh.c)
![](https://cdn.nlark.com/yuque/0/2024/webp/25607809/1708742620718-8aa89e3f-2c4d-4d6b-adf3-242cd3facccb.webp#averageHue=%232b2e36&clientId=u2c46e135-e44f-4&from=paste&id=u091953c4&originHeight=720&originWidth=1003&originalType=url&ratio=1.25&rotation=0&showTitle=false&status=done&style=none&taskId=u39f3ea2b-4db0-4f00-8d0d-a624b61e48f&title=)
trace02
成功过关。
### **trace03-04**

- trace03: run a foreground job.

在抄写完成后，我们可以直接通过trace03，(偷鸡了，原本应该是需要实现job control的，放在trace04，一起介绍)

- trace04: run a background job

![](https://cdn.nlark.com/yuque/0/2024/webp/25607809/1708742621204-e866b91d-5114-4375-8c12-e74ecd7d931c.webp#averageHue=%232b2e36&clientId=u2c46e135-e44f-4&from=paste&id=u66831465&originHeight=720&originWidth=1003&originalType=url&ratio=1.25&rotation=0&showTitle=false&status=done&style=none&taskId=u7b8a96e6-6513-4e24-a393-d9e78240350&title=)
trace03-04
与tshref的输出比较发现，我们的输出格式不对，因此，需要修改printf中的输出格式。除此之外，此trace开始需要作业号了，因此我们必须开始完成我们的job control部分了。
## **job control**
书上的代码是不断迭代成最终版本的，受限于篇幅，我们不展示中间过程版本，直接是最终版本了。**这部分需要看书到非本地跳转之前的所有部分。**
首先，为了写起来方便直观，定义几个宏:

```c
#define BLOCK(set, old_set) Sigprocmask(SIG_BLOCK, &(set), &(old_set))
 #define BLOCK_NOT_SAVE_OLD_SET(set) Sigprocmask(SIG_BLOCK, &(set), NULL)
 #define UNBLOCK(old_set) Sigprocmask(SIG_SETMASK, &(old_set), NULL)
 volatile sig_atomic_t FG_PID_GLOBALS;
```
修改后的eval()最终版本

```c
void eval(char *cmdline) 
 {
   char *argv[MAXARGS]; // argument list exec()
   char buf[MAXLINE]; // Holds modified commmand line.
   int bg; // should the job run in bg or fg?
   pid_t pid;
 
   strcpy(buf, cmdline);
   bg = parseline(buf, argv); 
   // constructing argv[MAXARGS] And return true if job is bg. iow, the last char is &.
 
   if (argv[0] == NULL)
     return; // Ignore empty lines.
 
 
   if (!builtin_cmd(argv)){
 
     sigset_t mask_all;
     sigset_t mask_one, prev_one;
 
     Sigfillset(&mask_all);
     Sigemptyset(&mask_one);
     Sigaddset(&mask_one, SIGCHLD);
     
     BLOCK(mask_one, prev_one); // Block SIGCHLD.
     
     pid = Fork();
 
     if (pid == 0){
       // child runs user job.
       UNBLOCK(prev_one); //Unblock SIGCHLD.
       setpgid(0, 0);
       if (execve(argv[0], argv, environ) < 0){
         printf("%s: Command not found. \n", argv[0]);
         exit(0);
       }
     }
     else {
       int state = bg ? BG : FG;
       BLOCK_NOT_SAVE_OLD_SET(mask_all);
       addjob(jobs, pid, state, cmdline);
       UNBLOCK(prev_one); // Unblock SIGCHLD.
 
       /* Parent waits for fg job to terminate.*/
       if (!bg){
         waitfg(pid);
       }
       else {
         // the job is bg.
         BLOCK_NOT_SAVE_OLD_SET(mask_all);
         printf("[%d] (%d) %s", pid2jid(pid), pid, cmdline);
       }  
       UNBLOCK(prev_one);//Unblock all signal
     } 
   }
 }
```
SIGCHLD信号处理程序。**其中，关于waitpid的参数，参考了writeup中的Hints部分。**

```c
void sigchld_handler(int sig) 
 {
   int old_errno = errno;
   pid_t pid;
   int status;
   sigset_t mask_all, prev_all; 
     
   sigfillset(&mask_all);  
 
   while((pid = waitpid(-1, &status, WNOHANG | WUNTRACED)) > 0)
   {
     BLOCK(mask_all, prev_all);
     struct job_t *job = getjobpid(jobs, pid);
     if (pid == fgpid(jobs)){
       FG_PID_G = pid;
     }
     deletejob(jobs, pid);
     UNBLOCK(prev_all);
   }
   errno = old_errno;
 }
```
最后，waitfg()函数我们顺手也能写出来了-.-

```c
void waitfg(pid_t pid)
 {
   sigset_t mask;
   sigemptyset(&mask);
 
   FG_PID_GLOBALS = 0;
   while (!FG_PID_GLOBALS)
     sigsuspend(&mask);
 }
```
![](https://cdn.nlark.com/yuque/0/2024/webp/25607809/1708742621146-53e68186-7534-40ce-b967-b21d46f44465.webp#averageHue=%232a3038&clientId=u2c46e135-e44f-4&from=paste&id=ua5389987&originHeight=1015&originWidth=1440&originalType=url&ratio=1.25&rotation=0&showTitle=false&status=done&style=none&taskId=u81d95020-0a97-4702-86e9-078b7fc6fd9&title=)
trace04
最后，我们成功产生了相同的输出
## **trace05(Process jobs builtin command)**
trace05与trace02类似，都是处理内置命令。修改builtin_cmd()函数，添加对应命令即可。

```c
int builtin_cmd(char **argv) 
 {
 
   if (!strcmp(argv[0], "quit"))// quit command.
     exit(0); 
   else if (!strcmp(argv[0], "&")) // Ignore singleton &. nothing is happen.
     return 1; 
   else if (!strcmp(argv[0], "jobs")){// jobs command.
     sigset_t mask_all, prev_all;
     Sigfillset(&mask_all);
 
     BLOCK(mask_all, prev_all);
     listjobs(jobs);
     UNBLOCK(prev_all);
     
     return 1; 
   }
   return 0;     /* not a builtin command */
 }
```
![](https://cdn.nlark.com/yuque/0/2024/webp/25607809/1708742621191-6eb97e0f-494b-4b15-904e-96b85f82ffc0.webp#averageHue=%23292d35&clientId=u2c46e135-e44f-4&from=paste&id=ud7103f04&originHeight=546&originWidth=746&originalType=url&ratio=1.25&rotation=0&showTitle=false&status=done&style=none&taskId=u74405fb4-5f4e-446a-b66f-836016be7ad&title=)
trace05
轻松通过。
## **trace06-08**

- trace06: Forward SIGINT to foreground job.
- trace07: Forward SIGINT only to foreground job.
- trace08: Forward SIGTSTP only to foreground job.

这三个trace有个问题需要注意，在我们上面的eval()函数中我们有一句setpid(0,0)，这是课本代码所没有的。
写这个语句的原因是，如果我们在我们的shell中运行tsh，对于我们的shell来说，由于tsh与其子进程都属于同一个进程组，我们如果按下control+C，会把tsh本身与其前台进程全部杀死(回忆关于信号的章节，信号的机制是基于进程组的)。
所以我们需要setgpid(0,0),这个语句会让tsh中的前台进程的进程组id修改成自身的进程id相同。这样对于shell来说，它的前台进程只有tsh一个，然后我们在tsh中小心编写对应的信号处理程序，即可只杀死前台进程，而不是连同tsh本身都被干掉。
**以上内容也来自writeup中的Hint部分。**
如果不注意区分tsh与其前台进程，trace05-06会发生明明写好了对应的信号处理程序，却看不到输出。原因是tsh本身也被杀死了or休眠了。
![](https://cdn.nlark.com/yuque/0/2024/webp/25607809/1708742621187-871b4d99-0afc-4c67-8afe-fd0ddf83ef86.webp#averageHue=%232a2e37&clientId=u2c46e135-e44f-4&from=paste&id=u0c40a581&originHeight=332&originWidth=860&originalType=url&ratio=1.25&rotation=0&showTitle=false&status=done&style=none&taskId=u62cb2799-18fe-49d4-8347-dcdb11ef306&title=)
setgpid(0, 0)
两个函数逻辑都很简单，比较容易写出。唯一要关注的kill的参数需要设置成-pid，因为按下control+C等，shell需要向整个进程组发送对应的信号。

```c
void sigint_handler(int sig) 
 {
   int old_errno = errno;
   
   pid_t pid = fgpid(jobs);
   if (pid != 0)
     kill(-pid, sig);
     
   errno = old_errno;
 }
 void sigtstp_handler(int sig) 
 {
   int old_errno = errno;
   pid_t pid = fgpid(jobs);
 
   if (pid != 0)
     kill(-pid, sig);
 
   errno = old_errno;
 }
```
最后，通过测试发现，我们还需要在tsh打印一些消息，来告知用户操作的结果。根据对应的输出格式，可以在sigchld_handler()，通过对waitpid的status的一些宏操作(也是书上的内容)与printf来组合实现。

```c
void sigchld_handler(int sig) 
 {
   int old_errno = errno;
   pid_t pid;
   int status;
   sigset_t mask_all, prev_all; 
     
   sigfillset(&mask_all);  
 
   while((pid = waitpid(-1, &status, WNOHANG | WUNTRACED)) > 0)
   {
     BLOCK(mask_all, prev_all);
     struct job_t *job = getjobpid(jobs, pid);
 
     if (pid == fgpid(jobs)){
       FG_PID_GLOBALS = pid;
     }
 
     if (WIFEXITED(status))  // Normal: delete job
     {
       deletejob(jobs, pid);
     }
     else if (WIFSIGNALED(status))  // C^C: print,and delete job
     {
       printf("Job [%d] (%d) terminated by signal %d\n", job->jid, job->pid, WTERMSIG(status));
       deletejob(jobs, pid);
     }
     else if (WIFSTOPPED(status)) // C^Z: print,and moditfy job state.
     {
       printf("Job [%d] (%d) stopped by signal %d\n", job->jid, job->pid, WSTOPSIG(status));
       job->state = ST;
     }
     else{
       deletejob(jobs, pid);
       printf("hahaha\n");
     }
 
     UNBLOCK(prev_all);
   }
 
   errno = old_errno;
 }
```
这样即可完成这三个trace。
![](https://cdn.nlark.com/yuque/0/2024/webp/25607809/1708742621196-89ca6560-5a74-46fa-ac31-9387f8a21909.webp#averageHue=%232a2f37&clientId=u2c46e135-e44f-4&from=paste&id=u70a2ea96&originHeight=1015&originWidth=1440&originalType=url&ratio=1.25&rotation=0&showTitle=false&status=done&style=none&taskId=u7e7c49d3-e071-4919-a705-c661f8da37f&title=)
trace08
## **trace09-10**

- trace09: Process bg builtin command
- trace10: Process fg builtin command

这两个trace要求我们实现内置的fg，bg命令。
因此，首先将对应的命令添加到buildin_cmd()中。

```c
if (!strcmp(argv[0], "bg") || !strcmp(argv[0], "fg")){ // bg or fg commands.
   do_bgfg(argv);
   return 1;
 }
```
之后编写处理函数do_bgfg():

```c
void do_bgfg(char **argv) 
 {
   struct job_t *job;
   int id;
   sigset_t mask_all, prev_all;
   Sigfillset(&mask_all);
 
   if (argv[1] == NULL){
     // single fg or bg.
     printf("%s command requires PID or %%jobid argument\n", argv[0]);
     return;
   }
   else if (sscanf(argv[1], "%%%d", &id) > 0){
     BLOCK(mask_all, prev_all);
     job = getjobjid(jobs, id);
     UNBLOCK(prev_all);
 
     if (job == NULL){
       // not found the job.
       printf("%%%d: No such job\n", id);
       return;
     }
   }
   else if(sscanf(argv[1], "%d", &id) > 0){
     BLOCK(mask_all, prev_all);
     job = getjobpid(jobs, id);
     UNBLOCK(prev_all); 
 
     if (job == NULL){
       printf("(%d): No such process\n", id);
       return;
     }
   }
   else{
     // not pid or jid.
     printf("%s: argument must be a PID or %%jobid\n", argv[0]);
     return;
   }
 
   if (!strcmp(argv[0], "bg")){
     kill(-(job->pid), SIGCONT);
     job->state = BG;
     printf("[%d] (%d) %s", job->jid, job->pid, job->cmdline);
   }
   else if (!strcmp(argv[0], "fg")){
     kill(-(job->pid), SIGCONT);
     job->state = FG;
     waitfg(job->pid);
   }
 }
```
代码整体比较简单，值得注意是需要先判断是否是单独的fg，bg命令，之后再通过sscanf做格式解析。因为sscanf第一个参数不可以是NULL，不然会有段错误。
正常做到这个trace的时候应该写不成上述样子，因为trace09-10并没有测试如果fg/bg的参数非法会怎样。这部分正常应该是在trace14才开始做的。
![](https://cdn.nlark.com/yuque/0/2024/webp/25607809/1708742621822-323cfaf0-3886-457c-bda2-cc3159ba74c9.webp#averageHue=%232a2f37&clientId=u2c46e135-e44f-4&from=paste&id=u78ab32ac&originHeight=1015&originWidth=1440&originalType=url&ratio=1.25&rotation=0&showTitle=false&status=done&style=none&taskId=uda28a48a-705a-4e7d-9fc2-8358ecdd814&title=)
trace10
## **trace11-16**

- trace11: Forward SIGINT to every process in foreground process group
- trace12: Forward SIGTSTP to every process in foreground process group
- trace13: Restart every stopped process in process group
- trace14： Simple error handling
- trace15: Putting it all together
- trace16: Tests whether the shell can handle SIGTSTP and SIGINT signals that come from other processes instead of the terminal.

由于我们前面每个都快了一点点，导致我们后边6个trace，直接就结束了。
图太多了，这里只展示下trace15与16的结果。
![](https://cdn.nlark.com/yuque/0/2024/webp/25607809/1708742621536-06801805-f7ed-43b7-b914-a60f4f346e0d.webp#averageHue=%23292e36&clientId=u2c46e135-e44f-4&from=paste&id=uc64ffc6d&originHeight=772&originWidth=1440&originalType=url&ratio=1.25&rotation=0&showTitle=false&status=done&style=none&taskId=uade90ebe-c990-4f7d-acbc-6a7cb8b15db&title=)
trace15
![](https://cdn.nlark.com/yuque/0/2024/webp/25607809/1708742621782-9b55be12-956e-4b7b-baf8-9f6b8937c707.webp#averageHue=%23292d35&clientId=u2c46e135-e44f-4&from=paste&id=u73dc4114&originHeight=512&originWidth=834&originalType=url&ratio=1.25&rotation=0&showTitle=false&status=done&style=none&taskId=u3b4c83ce-7a3f-4b57-9a49-51cec960773&title=)
trace16
## **后记**
原本想写个python脚本，来方便测试的。因为哪怕采用diff <(make rtestxx) <(make testxx)，每次也要修改两个地方，不太方便。但是这个实验很快做完了，也就不了了之。
