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
		TAminoAcid(const TAminoAcid& acid) : FName(acid.FName), FCodon(acid.FCodon), FId(acid.FId) {}
		TAminoAcid& operator =  (const TAminoAcid& acid) 
		{ 
			FName  = acid.FName;
			FCodon = acid.FCodon;
			FId    = acid.FId;
			return *this; 
		}

		//std::vector<std::string> total;
		std::string name() const override
		{
			return FName;
		}
		std::string getCodon() const
		{
			return FCodon;
		}
		char getId() const
		{
			return FId;
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
		std::vector<TAminoAcid> FAminoAcids;
		void Assign(const TProteinSequence& protseq)
		{
			for (int i = 0; i < protseq.FAminoAcids.size(); ++i)
			{
				FAminoAcids.push_back(protseq.FAminoAcids[i]);
			}
		}
	public:
		TProteinSequence() : FAminoAcids() {}
		TProteinSequence(const TProteinSequence& protseq)
		{
			Assign(protseq);
		}
		TProteinSequence& operator = (const TProteinSequence& protseq)
		{
			Assign(protseq);
			return *this;
		}
		bool isEmpty() const { return FAminoAcids.empty(); }
		std::string toString() const
		{
			std::string s = "";
			for (int i = 0; i < FAminoAcids.size(); ++i)
			{
				s += FAminoAcids[i].getId();
			}
			return s;
		}
		std::string toString2() const
		{
			std::string s = "";
			for (int i = 0; i < FAminoAcids.size(); ++i)
			{
				if (i > 0) s += ',';
				s += FAminoAcids[i].name();
			}
			return s;
		}
		void addAminoAcid(const TAminoAcid& a)
		{
			FAminoAcids.push_back(a);
		}
		bool canCombine(const std::string& s1, const std::string& s2) const
		{
			if (s1.back() == s2.front())
				return true;
			int len = min(s1.size(), s2.size());
			for (int i = 1; i < len; ++i)
			{
				std::string ss1 = s1.substr(s1.size() - i, i);
				std::string ss2 = s2.substr(0, i);
				if (ss1 == ss2)
					return true;
			}
			return false;
		}
		TProteinSequence operator + (const TProteinSequence& seq) const 
		{ 
			if (canCombine(toString(), seq.toString()))
			{
				TProteinSequence res(*this);
				for (int i = 1; i < seq.FAminoAcids.size(); ++i)
				{
					res.addAminoAcid(seq.FAminoAcids[i]);
				}
				return res;
			}
			return TProteinSequence();
		}

		std::string sequence() const
		{
			std::string str;
			for (int i = 0; i < FAminoAcids.size(); ++i)
			{
				str += FAminoAcids[i].getCodon();
			}
			return str;
		}
		std::string name() const
		{
			std::string str;
			for (int i = 0; i < FAminoAcids.size(); ++i)
			{
				str += FAminoAcids[i].name();
			}
			return str;
		}
	};

	class TTranslator
	{
	private:
		TTranslator(const TTranslator&);
		TTranslator& operator = (const TTranslator&);
	private:
		std::vector<TAminoAcid> FAmins;
	public:
		//TTranslator(const std::vector<TAminoAcid>&) {}
		//TTranslator(const TTTranslator& trans) {}
		TTranslator() : FAmins()
		{
			FAmins.push_back(TAminoAcid("None", "", 'n'));
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
		const TAminoAcid& searchAminoAcid(const std::string& codon)
		{
			for (int i = 0; i < FAmins.size(); ++i)
			{
				const TAminoAcid& acid = FAmins[i];
				if (acid.getCodon().find(codon) != std::string::npos)
				{
					return acid;
				}
			}
			return FAmins[0];
		}

		TProteinSequence getSequence(const std::string& str)
		{
			TProteinSequence seq;
			std::string tmp(str);
			while (tmp.length() >= 3)
			{
				std::string s = tmp.substr(0, 3);
				const TAminoAcid& acid = searchAminoAcid(s);
				if (acid.getCodon() !=  "")
				{
					seq.addAminoAcid(acid);
					tmp.erase(0, 3);
				}
				else
				{
					tmp.erase(0, 1);
				}
			}
			return seq;
		}
	};

	void menu()
	{
		TTranslator tr;

		std::cout << "Введите количество последовательностей нуклеотидов: " << std::endl;
		int cnt = n_ReadInt(INT_MAX);
		if (cnt == INT_MAX)
			return;
		std::vector<TProteinSequence> res;
		for (int i = 0; i < cnt; ++i)
		{
			std::cout << "Введите последовательность нуклеотидов: " << std::endl;
			std::string subseq;
			std::cin >> subseq;
			res.push_back(tr.getSequence(subseq));
			std::cout << tr.getSequence(subseq).toString() << std::endl;

		}
		TProteinSequence seq;
		for (int i = 0; i < res.size() - 1; ++i)
		{
			TProteinSequence seq = res[i] + res[i + 1];
		}
		//if (seq.isEmpty())
		//{
		//std::cout << "Не нашлось подходящих последовательностей, чтобы составить белок " << std::endl;
		//}
		//else
		//{
		std::cout << seq.toString();
		//}
		//const TAminoAcid& acid = tr.searchAminoAcid("AAA");
		//std::cout << "Acid: " << acid.name() << std::endl;

		//std::string str = "GGUACGGCUGUUAUU"; // "AAAGGG" -> {
		//std::string str_1 = "CAACCU";
		//TProteinSequence seq1 = tr.getSequence(str);
		//TProteinSequence seq2 = tr.getSequence(str_1);
		//TProteinSequence seq3 = seq1 + seq2;
		//std::cout << seq1.toString();
		//std::cout << seq3.toString();



		//TAminoAcid a1( acid );
		//TAminoAcid a2 = acid;
		//TAminoAcid a3 = a2;



	}
}