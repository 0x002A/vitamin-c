#include <stdlib.h>
#include <stdio.h>

#include <config.h>

vitc_config *
vitc_init(void)
{
    vitc_config *cfg = (vitc_config*)malloc(sizeof(vitc_config));

    // init with default values
    cfg->inputFiles= NULL;
    cfg->alignmentGraphs= NULL;
    cfg->graphsToVisualize= NULL;
    cfg->algorithm= NULL;
    cfg->alignmentMethod= NULL;
    cfg->scoringTable= NULL;
    cfg->saveAll = 0;
    cfg->saveAdditional = 0;
    cfg->saveAlignmentTree = 0;
    cfg->outputFilename = NULL;
    cfg->generateHTML = 0;

    return cfg;
}

void
vitc_free(vitc_config **handle)
{
    free(*handle);
    *handle = NULL;
}

void vitc_set_defaults(vitc_config *handle)
{
    if (!handle)
    {
        fprintf(stderr, "%s\n", "Tried to perform operation on invalid vitamin-c handle! Aborting!");
    }

    /*
     * Pointers to static string literals are valid trough the whole execution of the program
     */

    if (!handle->algorithm)
    {
        handle->algorithm = "subVF2";
    }


    if (!handle->alignmentMethod)
    {
        handle->algorithm = "GREEDY";
    }
}