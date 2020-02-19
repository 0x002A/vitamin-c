#include <stdlib.h>

#include <config.h>

vitc_config
*vitc_init(void)
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