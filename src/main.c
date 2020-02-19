#include "banner.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <vitc/config.h>

void parseArguments(int argc, char* argv[]);
void printHelp();

int
main(int argc, char* argv[])
{  	
  printStartupBanner();
  parseArguments(argc, argv);

  return 0;
}


void
parseArguments(int argc, char* argv[])
{
  vitc_config *vitc = vitc_init();
  char c;
  const size_t requiredArgsCount = 3;
  size_t countedRequiredArgs = 0;

  while((c = getopt(argc, argv, "hi:c:v:a:m:t:lsgo:r")) != -1 )
  {
    switch (c)
    {
      case 'h':
        printHelp();
        exit(0);
        break;
      case 'i':
        ++countedRequiredArgs;
        vitc->inputFiles = optarg;
        break;
      case 'c':
        ++countedRequiredArgs;
        vitc->alignmentGraphs = optarg;
        break;
      case 'v':
        ++countedRequiredArgs;
        vitc->graphsToVisualize = optarg;
        break;
      case 'a':
        vitc->algorithm = optarg;
        break;
      case 'm':
        vitc->alignmentMethod = optarg;
        break;
      case 't':
        vitc->scoringTable = optarg;
        break;
      case 'l':
        vitc->saveAll = 1;
        break;
      case 's':
        vitc->saveAdditional = 1;
        break;
      case 'g':
        vitc->saveAlignmentTree = 1;
        break;
      case 'o':
        vitc->outputFilename = optarg;
        break;
      case 'r':
        vitc->generateHTML = 1;
        break;
      case '?':
        fprintf(stderr, "Unrecognized option!\n" );
        break;
    }
  }

  if (countedRequiredArgs != requiredArgsCount)
  {
    fprintf(stderr, "Not all required arguments have been set. Aborting!\n");
    exit(1);
  }

  vitc_set_defaults(vitc);

  vitc_free(&vitc);
}

void
printHelp()
{
  printf("usage: vitamin-c %s\n", "[ -h | -i | -c | -v | -d ] [-a] [-m] [-t] [-l] [-s] [-g]");
  printf("for example: vitamin-c %s\n\n", "-ga subVF2 -i g1.graph g2.graph g3.graph");

  const char* paramFormat = "%s:\t%s\n";
  
  printf("Required arguments (These arguments are mutually exclusive):\n\n");
  
  printf(paramFormat, "-h", "show help and exit");
  printf(paramFormat, "-i", "input files");
  printf(paramFormat, "-c", "do alignment with two graphs and save co-optimals");
  printf(paramFormat, "-v", "get a visual representation of the given graphs");

  printf("\n");
  printf("Optional arguments:\n\n");

  printf(paramFormat, "-a", "algorithm to be used (BK|VF2|subVF2), default: subVF2");
  printf(paramFormat, "-m", "multiple alignment method (GREEDY|file), default: GREEDY");
  printf(paramFormat, "-t", "custom lable scoring table");
  printf(paramFormat, "-l", "save all resulting graphs");
  printf(paramFormat, "-s", "save additional version of the alignment graph with shorter node ids");
  printf(paramFormat, "-g", "save the alignment tree in Newick-format");
  printf(paramFormat, "-o", "name of the output file");
  printf(paramFormat, "-r", "generate interactive graph representation of the consensus graph");
}