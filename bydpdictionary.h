
#ifndef _BYDPDICTIONARY_H
#define _BYDPDICTIONARY_H

#include <String.h>
#include <File.h>
#include <TextView.h>
#include <ListView.h>
#include <Font.h>

#include "bydpconfig.h"

#define A_BOLD 1
#define A_ITALIC 2
#define A_COLOR0 4
#define A_COLOR1 8
#define A_COLOR2 16
#define A_MARGIN 32
#define A_SUPER 64

	class ydpDictionary {
		public:
			ydpDictionary(BTextView *output, BListView *dict, bydpConfig *config);
			~ydpDictionary();

			void GetDefinition(int index);
			int OpenDictionary(const char *index, const char *data);
			int OpenDictionary(void);
			int FindWord(const char *word);
			void CloseDictionary(void);

			int *wordPairs;		// # indeksow na liscie dictList

		private:
			int ReadDefinition(int index);
			void FillWordList(void);
			void ParseRTF(void);
			void UpdateAttr(int oldattr, int newattr);
			char *ParseToken(char *def);
			void ClearWordList(void);
//			void FullFillList(void);
			int ScoreWord(const char *w1, const char *w2);
			int BeginsFindWord(const char *word);
			int FuzzyFindWord(const char *word);
		    int min3(const int a, const int b, const int c);
		    int editDistance(const char*slowo1, const char*slowo2);
		    char *ConvertToUtf(BString line);
		    char *ConvertFromUtf(const char *input);

			// GUI data holders
			BTextView *outputView;
			BListView *dictList;

			// configuration holder
			bydpConfig *cnf;

			// dictionary data
			BFile fIndex, fData;
			int wordCount;
			unsigned long *indexes;
			char **words;
			BString curDefinition;

			// caching stuff
			struct dictionaryCache {
				int wordCount;
				char **words;
				unsigned long *indexes;
			} dictCache[2];
			int lastresult, lastIndex;
			bool dictionaryReady;

			// parser variables
			char *def;
			int newline_, newattr, newphon;
			int textlen;
			BString line;
	};

#define TABLE_UTF8 { \
		"~", \
		".", ".", "<o>", "<3>", ".", "<|>", "<E>", "<^>", "<e>", \
		"θ", "<i>", "<a>", "Ś", ":", "´", "Ź", "ŋ", \
		".", ".", ".", ".", ".", ".", "ð", "æ", \
		".", ".", ".", "ś", ".", ".", "ź", ".", \
		"Ą", ".", "Ł", "¤", "Ľ", "Ś", "§", "¨", \
		"Š", "Ş", "Ť", "Ź", "­", "Ž", "Ż", "°", \
		"ą", ".", "ł", "´", "ľ", "ś", ".", "¸", \
		"ą", "ş", "ť", "ź", ".", "ž", "ż", "Ŕ", \
		"Á", "Â", "Ă", "Ä", "Ľ", "Ć", "Ç", "Č", \
		"É", "Ę", "Ë", "Ĕ", "Í", "Î", "Ď", "Ð", \
		"Ń", "Ň", "Ó", "Ô", "Õ", "Ö", "×", "Ř", \
		"Ù", "Ú", "Û", "Ü", "Ý", "Ţ", "ß", "ŕ", \
		"á", "â", "ã", "ä", "ľ", "ć", "ç", "č", \
		"é", "ę", "ë", "ì", "í", "î", "ď", "đ", \
		"ń", "ň", "ó", "ô", "õ", "ö", "÷", "ř", \
		"ù", "ú", "û", "ü", "ý", "ţ", "." }

#endif
