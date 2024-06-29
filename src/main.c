#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "huffman.h"

/**
 * Prints the help message for the HuffmanCompressor utility.
 */
void printHelp()
{
    printf("CHuffmanCompressor - Huffman Coding Compression Utility\n\n");
    printf("Usage:\n");
    printf("    huffman_compressor encode <input file> <output file>\n");
    printf("    huffman_compressor decode <input file> <output file>\n\n");
    printf("Options:\n");
    printf("    --help, -h     Show this help message\n\n");
    printf("Examples:\n");
    printf("    huffman_compressor encode henok.txt henok.bin\n");
    printf("    huffman_compressor decode henok.bin henok.txt\n");
}

/**
 * Encodes the input file using Huffman coding and saves the result to the output file.
 *
 * @inputfilename inputfilename The name of the input file.
 * @outputfilename outputfilename The name of the output file.
 */
void encoding(const char *inputfilename,const char *outputfilename)
{
    FILE *inputfile = fopen(inputfilename, "rb");

    if (inputfilename == NULL)
    {
        fprintf(stderr, "Error: Failed to open file %s\n", inputfilename);
        return EXIT_FAILURE;
    }

    fseek(inputfile, 0, SEEK_END);
    unsigned int size = ftell(inputfile);
    rewind(inputfile);

    unsigned char *data = malloc(size + 1);

    if(data == NULL)
	{
		fprintf(stderr, "Error: Failed to allocate memory\n");
        fclose(inputfilename);
        exit(EXIT_FAILURE);
	}
	size_t bytesRead = fread(data, 1, sizeof(data), inputfile);
	if (bytesRead != size)
		{
        fprintf(stderr, "Error: Failed to read the entire file %s\n", inpufFileName);
        free(data);
        fclose(inputfilename);
        exit(EXIT_FAILURE);

		}
    data[size + 1] = '\0';

    fclose(inputfile);


}

/**
 * The main function of the HuffmanCompressor utility.
 *
 * @ argc The number of command line arguments.
 * @ argv An array of command line arguments.
 * @return The exit status of the program.
 */
int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *opration = argv[0];
    const char *inputfilename = argv[1];
    const char *outputfilename = argv[2];

    if(argc == 2 && strcmp(opration,'--help') == 0 || strcmp(opration,'h') == 0)
    {
        printHelp();
        return EXIT_SUCCESS;
    }

    if (argc != 3)
    {
        fprintf(stderr, "Error: Invalid number of arguments\n");
        printHelp();
        return EXIT_FAILURE;
    }


    if(strcmp(opration, "encode") == 0)
    {
        encoding(inputfilename, outputfilename);
    }
    else if(strcmp(opration,"decode") == 0)
    {
        decodefile(inputfilename, outputfilename);
    }
    else
    {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    return 0;
}
