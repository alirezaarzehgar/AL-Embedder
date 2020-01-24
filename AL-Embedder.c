#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

extern void banner();

int main(int argc, char** argv)
{
	banner();
	// checking argument
	if(argc < 2)
	{
		printf("\033[96margument \033[31mnot\033[96m found!\033[0m\n");
                printf(
                        "\033[31mUSING\033[0m :\n"
                        "       ./AL-Image-Embedder [\033[31mOPTION\033[0m] [\033[31mFIRST MEDIA\033[0m] [\033[31mSECOND MEDIA\033[0m] [\033[31mOUTPUT\033[0m]\n"
                        "\033[31mOPTION\033[0m :\n"
                        "       --on    embedding     -   code\n"
                        "       --off   un embedding  -   de code\n"
                        "\n"
                        "\033[31mEXAMPLE\033[0m :\n"
                        "       ./AL-Image-Embedder --on /usr/bin/ls /usr/share/backgrounds/*.jpg test.png\n"

                );

		return -1;
	}


	if(fopen(argv[2], "r") == NULL)
	{
		printf("\033[31mfirst argument \033[36mnot\033[31m exeist file!\n");
                printf(
                        "\033[31mUSING\033[0m :\n"
			"       ./AL-Image-Embedder [\033[31mOPTION\033[0m] [\033[31mFIRST MEDIA\033[0m] [\033[31mSECOND MEDIA\033[0m] [\033[31mOUTPUT\033[0m]\n"
                        "\033[31mOPTION\033[0m :\n"
                        "       --on    embedding     -   code\n"
                        "       --off   un embedding  -   de code\n"
                        "\n"
                        "\033[31mEXAMPLE\033[0m :\n"
                        "       ./AL-Image-Embedder --on /usr/bin/ls /usr/share/backgrounds/*.jpg test.png\n"

                );

		return -1;
	}



	// define a var for create command
        char comm[1024];

	// checking option
	if(strstr(argv[1], "--on"))
	{
		printf("\033[31mstart file Embedding!\n");
		if(argc < 5)
		{
			printf("\033[31mout put name \033[36mnot\033[31m found!\n");
			return -1;
		}
		// Zip
		sprintf(comm, "zip -r tmp.zip %s", argv[2]);
		// execute
		system(comm);

		// embed exe to zip
                sprintf(comm, "cat %s tmp.zip > %s", argv[3], argv[4]);
		// execute
                system(comm);
		printf("\033[31mEmbed file to image!\n");

		remove("tmp.zip");

	}else if(strstr(argv[1], "--off"))
	{
		printf("\033[31mstart file Extracting!\n");
		sprintf(comm, "unzip %s", argv[2]);
		system(comm);
	}
	printf("\033[31mFinish:)\n");
	return 0;
}

extern void banner()
{
	printf(
"			            \033[37m _________________\n\033[0m"
"			            \033[101;37m|                |\\\033[0m\n"
"			            \033[101;37m|                |_\\\033[0m\n"
"			            \033[101;37m|    ___________    |\033[0m \n"
"	         \033[37m        ___________\033[101;37m|__ |           |   |\033[0m\n"
"                \033[37m██      |  \033[37m██|\033[31m██████████\033[101;37m|__ °  /\\   |   |\033[0m\n"
"                \033[37m█████████████|\033[31m████EXE██████\033[101;31m├─\033[101;37m /  \\  |   |\033[0m\n"
"		\033[37m██      |_\033[37m_██|\033[31m██████████\033[101;37m|  /\\/    \\ |   |\033[0m\n"
"			            \033[101;37m|   |_/________\\|   |\033[0m\n"
"			            \033[101;37m|                   |\033[0m\n"
"			            \033[101;37m|___________________|\033[0m\n"

	);
}
