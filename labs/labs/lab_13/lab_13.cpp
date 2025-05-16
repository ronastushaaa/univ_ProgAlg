#include "lab_13.h"


namespace lab_13
{
	class TBase
	{
		virtual std::string index() const = 0;
	};

	class TAminoAcid : public TBase
	{
	private:
		std::string              FName;
		std::vector<std::string> FCodon;
	public:
		TAminoAcid(const std::string& name, const std::vector<std::string>& codon) : FName(name), FCodon(codon) {}
		std::vector<std::string> total;
		std::string index() const override
		{
			return FName;
		}
		std::vector<std::string> getcodon() const
		{
			return FCodon;
		}
		void total_aminoAcid(std::vector<std::string> condon)
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
		}
	};

	class TProtein : public TBase
	{
	private:
		std::vector<TAminoAcid> aminoAcids;
	public:
		void addAminoAcid(const TAminoAcid& a)
		{
			aminoAcids.push_back(a);
		}
	};
}