#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int uid, gid, size = 2048;
	char *uid_name, *gid_name;
	unsigned int list[size];
	int group_number = getgroups(size, list) - 1;
	struct group *gr;
	struct passwd *pw;

	if(argc == 1)
	{
		uid = getuid();
		gid = getgid();
		gr = getgrgid(gid);
		pw = getpwuid(uid);
		gid_name = gr->gr_name;
		uid_name = pw->pw_name;
	}
	if(argc == 2)
	{
		uid_name = argv[1];
		pw = getpwnam(uid_name);
		gr = getgrnam(uid_name);
		uid = pw->pw_uid;
		gid = gr->gr_gid;
		gid_name = gr->gr_name;	 
	}
	printf("uid = %d (%s) ", uid, uid_name);
        printf("gid = %d (%s) ", gid, gid_name);
        printf("group = %d (%s) ", list[group_number], uid_name);

        int i = 0;
        for(i = 0; i < group_number; i++)
        {
                struct group *current_group = getgrgid(list[i]);
                printf("%d (%s) ", list[i], current_group->gr_name);
        }


}



























