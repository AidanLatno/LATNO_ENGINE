#include "../declarations/Behavior.h"

namespace Latno
{
	std::vector<Latno::Behavior*> BehaviorList;

	void Behavior::AddTag(std::string TagToAdd)
	{
		tagList.push_back(TagToAdd);
		int x = tagList.size();
	}

	void Behavior::RemoveTag(std::string TagToRemove)
	{
		for (int i = 0; i < tagList.size() - 1; i++) {
			if (tagList[i] == TagToRemove) {
				tagList.erase(tagList.begin() + i);
			}
		}

	}

	void Behavior::ClearTags()
	{
		tagList.clear();
	}

	std::vector<std::string> Behavior::GetTagList()
	{
		return tagList;
	}

	bool Behavior::IfHasTag(std::string Tag)
	{
		for (std::string element : tagList)
			if (element == Tag) return true;
		return false;
	}

	int Behavior::GetID() { return id; }

	void Behavior::SetID(int value) { if (id == -1) id = value; }
}
