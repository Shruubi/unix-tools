#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define get_input_buffer_size(x) sizeof(char) * x

typedef struct CMD_NODE {
        char* data;
        struct CMD_NODE* next;
} node;

void print_prompt(void);
void parse_command(char*);
void add_node_to_list(node*, char*);

int
main(int argc, char* argv[])
{
        char* buff = (char*)malloc(get_input_buffer_size(1024));
        size_t bytes_read;
        int fd = fileno(stdin);

        print_prompt();
        while((bytes_read = read(fd, buff, 1024)) > 0) {
                parse_command(buff);
                memset(buff, 0, 1024);
                print_prompt();
        }

        memset(buff, 0, 1024);
        free(buff);
        return(0);
}

void
print_prompt(void)
{
        char* cwd = getcwd(NULL, 0);
        char* login = getlogin();

        printf("%s@%s => ", login, cwd);
        fflush(stdout);
}

void
parse_command(char* buff)
{
        char* tmp = (char*)malloc(get_input_buffer_size(1024));
        memcpy(tmp, buff, 1024);

        char* cmd = strtok(tmp, " \0");
        char* t;

        node* root = (node*)malloc(sizeof(node));
        root->next = NULL;
        root->data = cmd;

        while((t = strtok(NULL, " \0")) != NULL) {
                add_node_to_list(root, t);
        }

        node* ptr = root;
        do {
                printf("%s\n", ptr->data);
                ptr = ptr->next;
        } while(ptr != NULL);
        
}

void
add_node_to_list(node* root_node, char* data)
{
        node* ptr = root_node;
        node* prev_ptr = NULL;

        while(ptr != NULL) {
                prev_ptr = ptr;
                ptr = ptr->next;
        }

        ptr = (node*)malloc(sizeof(node));
        ptr->next = NULL;
        ptr->data = data;

        prev_ptr->next = ptr;
}
