#pragma once

typedef struct
{
  const char    *inputFiles;
  const char    *alignmentGraphs;
  const char    *graphsToVisualize;
  const char    *algorithm;
  const char    *alignmentMethod;
  const char    *scoringTable;
  _Bool         saveAll;
  _Bool         saveAdditional;
  _Bool         saveAlignmentTree;
  const char*   outputFilename;
  _Bool         generateHTML;
} vitc_config;

vitc_config *vitc_init(void);
void vitc_free(vitc_config **handle);
void vitc_set_defaults(vitc_config *handle);