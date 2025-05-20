#include "lab_13.h"


namespace lab_13
{
	class TBase
	{
		virtual std::string name() const = 0;
	};

	class TAminoAcid : public TBase
	{
	private:
		std::string FName;  // имя   (Глицин)
		std::string FCodon; // кодон (GGU,GGC,GGA,GGG,)
		char        FId;    // id    (G)
	public:
		TAminoAcid(const std::string& name, const std::string& codon, char id) : FName(name), FCodon(codon), FId(id) {}
		//std::vector<std::string> total;
		std::string name() const override
		{
			return FName;
		}
		std::string getCodon() const
		{
			return FCodon;
		}
		/*void total_aminoAcid(std::vector<std::string> condon)
		{
			for (int i = 0; i < condon.size(); ++i)
			{
				total.push_back(condon[i]);
			}
		}
		void search_aminoAcid(std::string nucleotide)
		{
			for (int i = 0; i  < nucleotide.size(); ++i)
			{
				auto it = std::find(total.begin(), total.end(), nucleotide[i] + nucleotide[i + 1] + nucleotide[i + 2]);
				if (nucleotide.size() - i > 1 && it != total.end())
				{
					return 
				}
			}
		}*/
	};

	class TProteinSequence : public TBase
	{
	private:
		std::vector<TAminoAcid> aminoAcids;
	public:
		void addAminoAcid(const TAminoAcid& a)
		{
			aminoAcids.push_back(a);
		}
		std::string sequence() const
		{
			std::string str;
			for (int i = 0; i < aminoAcids.size(); ++i)
			{
				str += aminoAcids[i].getCodon();
			}
			return str;
		}
		std::string name() const
		{
			std::string str;
			for (int i = 0; i < aminoAcids.size(); ++i)
			{
				str += aminoAcids[i].name();
			}
			return str;
		}
	};

	class TTranslator
	{
	private:
		std::vector<TAminoAcid> FAmins;
	public:
		TTranslator() : FAmins()
		{
			FAmins.push_back(TAminoAcid("Глицин", "GGU,GGC,GGA,GGG,", 'G'));
			FAmins.push_back(TAminoAcid("Аланин", "GCU,GCC,GCA,GCG,", 'A'));
			FAmins.push_back(TAminoAcid("Валин", "GUU,GUC,GUA,GUG,", 'V'));
			FAmins.push_back(TAminoAcid("Изолейцин", "AUU,AUC,AUA,", 'I'));
			FAmins.push_back(TAminoAcid("Лейцин", "UUA,UUG,CUU,CUC,CUA,CUG,", 'L'));
			FAmins.push_back(TAminoAcid("Пролин", "CCU,CCC,CCA,CCG,", 'P'));
			FAmins.push_back(TAminoAcid("Серин", "UCU,UCC,UCA,UCG,AGU,AGC", 'S'));
			FAmins.push_back(TAminoAcid("Треонин", "ACU,ACC,ACA,ACG,", 'T'));
			FAmins.push_back(TAminoAcid("Цистеин", "UGU,UGC,", 'C'));
			FAmins.push_back(TAminoAcid("Местионин", "AUG,", 'M'));
			FAmins.push_back(TAminoAcid("Аспарагиновая кислота", "GAU,GAC,", 'D'));
			FAmins.push_back(TAminoAcid("Аспарагин", "AAU,AAC,", 'N'));
			FAmins.push_back(TAminoAcid("Глутаминовая кислота", "GAA,GAG,", 'E'));
			FAmins.push_back(TAminoAcid("Глутамин", "CAA,CAG,", 'Q'));
			FAmins.push_back(TAminoAcid("Лизин", "AAA,AAG,", 'K'));
			FAmins.push_back(TAminoAcid("Аргинин", "CGU,CGC,CGA,CGG,AGA,AGG,", 'R'));
			FAmins.push_back(TAminoAcid("Гистидин", "CAU,CAC,", 'H'));
			FAmins.push_back(TAminoAcid("Фенилаланин", "UUU,UUC,", 'F'));
			FAmins.push_back(TAminoAcid("Тирозин", "UAU,UAC,", 'Y'));
			FAmins.push_back(TAminoAcid("Триптофан", "UGG,", 'W'));
		};
		const TAminoAcid& searchAminoAcid(std::string amin)
		{
			for (int i = 0; i < FAmins.size(); ++i)
			{
				if (FAmins[i].getCodon().find(amin) != std::string::npos)
				{
					return FAmins[i];
				}
			}
		}
	};
}