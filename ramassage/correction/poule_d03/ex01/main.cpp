



#include  "dictionary.hh"

int main (__attribute__((unused)) int argc, char **argv)
{
  std::vector<std::string>    words;

  words.push_back(argv[1]);
  words.push_back(argv[2]);
  words.push_back(argv[3]);
  words.push_back(argv[4]);
  words.push_back(argv[5]);
  words.push_back(argv[6]);
  words.push_back(argv[7]);
  words.push_back(argv[8]);
  words.push_back(argv[9]);
  words.push_back(argv[10]);

  Dictionary                  dico("Larousse", words);
  dico.FillDictionary();
  dico.ShowDictionary();
  return 0;
}
