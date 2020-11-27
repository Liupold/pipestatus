#include <sys/stat.h>
#include <string.h>
#include "deps.h"

#define VERSION "0.1a"

void
main_loop(const string fifo_path, const string Template, const string exec_cmd) {
        mkfifo(fifo_path.c_str(), 0666);
        const vector<string> init_data = parseTemplate(Template);
        vector<string> curr_data = init_data;
        cat_string(init_data);
        if (system(exec_cmd.c_str())) {
                cerr << "exec falied!";
        }

        ifstream infile(fifo_path, ios::out);
        string line;
        while (getline(infile, line)) {
                parse_fifo_input(line, init_data, curr_data);
                cat_string(curr_data);
        }
}

int
main(int argc, char** argv) {
        string Template, fifo_path, exec_cmd="";
        for (int i=1; i < argc; i++) {
                if (!strcmp(argv[i], "-v") || !strcmp(argv[i], "--version")) {
                        cout << "pipestatus-" << VERSION << endl; exit(0);
                }
                else if (!strcmp(argv[i], "-t") || !strcmp(argv[i], "--template")) {
                        Template = argv[i + 1];
                }
                else if (!strcmp(argv[i], "-f") || !strcmp(argv[i], "--fifopath")) {
                        fifo_path = argv[i + 1];
                }
                else if (!strcmp(argv[i], "-e") || !strcmp(argv[i], "--exec")) {
                        exec_cmd = argv[i + 1];
                }
                else if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) {
                        cout << "pipestatus [-v/-h] -e [exec] -t [TEMPLATE] -f [fifopath]" << endl;
                        exit(0);
                }
        }

        if (Template.size() > 0 && fifo_path.size() > 0) {
                main_loop(fifo_path, Template, exec_cmd);
        } else {
                cerr << "Invalid input!" << endl;;
                cout << "pipestatus [-v/-h] -e [exec] -t [TEMPLATE] -f [fifopath]" << endl;
                exit(2);
        }
        return 0;
}
