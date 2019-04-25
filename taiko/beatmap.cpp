#include "beatmap.h"

Beatmap::Beatmap(const std::string& path)
{
	std::string path_header = path.substr(0, path.find_last_of("\\") + 1);

	std::istringstream iss;
	std::ifstream f;
	f.open(path);

	std::string buffer;

	std::vector<float> hit_objects;

	while (std::getline(f, buffer))
	{
		if (audio_filename.empty() && buffer.substr(0, buffer.find_first_of(":")) == "AudioFilename")
			this->audio_filename = path_header + buffer.substr(buffer.find_first_of(":") + 2);

		if (title.empty() && buffer.substr(0, buffer.find_first_of(":")) == "Title")
			this->title = buffer.substr(buffer.find_first_of(":") + 1);

		// if (background.empty() && buffer.substr(0, buffer.find_first_of(":")) == "Background")
			// background = path_header + buffer.substr(buffer.find_first_of(":") + 2);

		if (buffer == "[HitObjects]")
		{
			while (std::getline(f, buffer))
			{
				if (buffer == "\n") break;

				unsigned int time;

				std::string str;

				iss.str(buffer);
				// get x
				std::getline(iss, str, ',');			
				// get y
				std::getline(iss, str, ',');
				// get time
				std::getline(iss, str, ',');

				iss.str(str);
				iss >> time;

				std::cout << time << std::endl;

				this->hit_objects.push_back(time);
				iss.clear();
			}
		}
	}

	f.close();
}