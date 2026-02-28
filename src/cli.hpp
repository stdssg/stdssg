#pragma once

namespace stdssg::cli {
    int run(int argc, char** argv);
    
    void print_help();
    void print_version();
    
    int handle_init();
    int handle_build();
    int handle_serve(); // TODO
}
