#include <cstdio>
class File {
private:
    FILE* ptr;
public:
    File(char *path_name): 
        ptr(fopen(path_name, "r")) {}
    ~File() {
        fclose(ptr);
    }
};