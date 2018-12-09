#include <Objidl.h>

/**
PMyData: The processed and interpreted frames ant his details and objects are coming from the record.
*/
struct TMyData;
typedef TMyData *PMyData;

struct TMyData
{
/**
  PlateString: Best license plate number of the plate group
  */
	const char * PlateString; 		
	/**
	PlateXML: Plate group data in standard XML string
	*/
	const char * PlateXML; 		
	/**
	LastError: Laast config error ex: bad file extensions, bad config data... Default: empty
	*/
	const char * LastError; 		
	
};

/**
TImageSource: Object recognizer, the input record of the necessary information for the ALPR processor modules.
*/
struct TImageSource;
typedef TImageSource *PImageSource;
struct TImageSource
{	
	/***
MyImageFile: Source image
*/
	char * MyImageFile; 	
};

/**
TALPRInit: Object recognizer initialise data, the input record of the necessary Initialise information for the ALPR processor modules.
*/
struct TALPRInit;
typedef TALPRInit *PALPRInit;
struct TALPRInit
{	
	/* Set country chars
      Recognize a plate tyle
      eu: All countries in European Union
      us: All Member States of the US
      au: Australia
      kr: Korean plates
      mx: Mexico plate
      vn: vietnamese 2 line plates
	*/
	char * country;
		/* Set plate results numbers, first the best Confidence */
	int topn;
};


/**
SetLicenceKey: ALPR processor license keys validation. Only the initialization
*/
extern "C" __declspec(dllexport) int SetLicenceKey(int key1,char *key2);

/**
StartALPR: Object analizing, recognizing and reading process from file.
*/
extern "C" __declspec(dllexport)  TMyData *  StartALPR(TImageSource *aTImageSource);

/**
StartALPR: Object analizing, recognizing and reading process from IStream.
*/
extern "C" __declspec(dllexport)  TMyData *  StartALPR2(IStream & stream);

/**
FreeResult: After results, memory free.
*/
extern "C" __declspec(dllexport)  int FreeResult(TMyData * iMyData);

/**
InitializeALPR: Load ALPR processor libraries and runtime datas
*/
extern "C" __declspec(dllexport)  int InitializeALPR(TALPRInit *ALPRInit);

/**
Free ALPR processor libraries and runtime datas
*/
extern "C" __declspec(dllexport)  int ReleaseALPR();





