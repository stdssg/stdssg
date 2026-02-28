#include "cli.hpp"
#include <exception>
#include <iostream>

#include "stdssg.hpp"
#include "site_builder.hpp"

const char nl = '\n';

namespace stdssg::cli {
void print_help() {
    std::cout << stdssg::NAME << " v" << stdssg::VERSION << " - Help" << nl;
    std::cout << "Usage:" << nl;
    std::cout << "  stdssg init          Initialize new project" << nl;
    std::cout << "  stdssg build         Build static site" << nl;
    // TODO std::cout << "  stdssg serve         TODO" << nl;
    std::cout << "  stdssg -h, -help     Show help" << nl;
    std::cout << "  stdssg -v, -version  Show version" << nl;
}

void print_version() {
    std::cout << stdssg::NAME << " v" << stdssg::VERSION << nl;
}

int handle_init() {
    SiteBuilder builder;
    builder.init();
    return 0;
}

int handle_build() {
    SiteBuilder builder;
    builder.build();
    return 0;
}

int run(int argc, char** argv) {
    try {
        if (argc < 2) {
            std::cout << "Use 'stdssg -h' to get a list of available commands" << nl;
            return 0;
        }

        std::string cmd = argv[1];

        if (cmd == "-h" || cmd == "-help")
            return (print_help(), 0);

        if (cmd == "-v" || cmd == "-version")
            return (print_version(), 0);

        if (cmd == "init")
            return handle_init();

        if (cmd == "build")
            return handle_build();

        std::cerr << "Unknown command: " << cmd << nl;
        std::cout << "Use 'stdssg -h' to get a list of available commands" << nl;
        return 1;
    } catch (const std::exception& err) {
        std::cerr << "Fatal error: " << err.what() << nl;
        return 1;
    }
}
}
