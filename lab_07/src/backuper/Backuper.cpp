//
// Created by Aleksandr Mikhailov on 01.12.2024.
//

#include "Backuper.h"

Backuper::Backuper(std::string inputFile, std::string outputFile) : inputFile_(std::move(inputFile)),
                                                                    outputFile_(std::move(outputFile)),
                                                                    input_(inputFile_),
                                                                    output_(outputFile_) {
    if(not input_.good()) {
        std::ofstream outfile (inputFile_);
        input_ = std::ifstream(inputFile_);
        // throw std::logic_error("Input file cannot be opened");
    }

    if(not output_.good()) {
        throw std::logic_error("Output file cannot be opened");
    }
}
