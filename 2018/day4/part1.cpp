#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

typedef enum {
	BEGINS,
	FALLS_ASLEEP,
	WAKES_UP
} guard_status_t;

typedef struct {
	unsigned month;
	unsigned day;
	unsigned minute;
} timestamp_t;

typedef struct {
	unsigned guard_number;
	guard_status_t status;
	timestamp_t timestamp;
} entry_t;

bool sort_func(const entry_t &lhs, const entry_t &rhs)
{
	if (lhs.timestamp.month == rhs.timestamp.month) {
		if (lhs.timestamp.day == rhs.timestamp.day) {
			return lhs.timestamp.minute < rhs.timestamp.minute;
		}
		return lhs.timestamp.day < rhs.timestamp.day;
	}
	return lhs.timestamp.month < rhs.timestamp.month;
}

int main()
{
	std::string line;
	std::vector<entry_t> entries;
	while (std::getline(std::cin, line)) {
		auto first_dash_pos = line.find("-");
		auto second_dash_pos = line.find("-", first_dash_pos + 1);
		auto month_str = line.substr(first_dash_pos + 1, second_dash_pos - first_dash_pos - 1);
		unsigned month = std::stoi(month_str);
		auto space_pos = line.find(" ");
		auto day_str = line.substr(second_dash_pos + 1, space_pos - second_dash_pos - 1);
		unsigned day = std::stoi(day_str);
		auto colon_pos = line.find(":");
		auto hour_str = line.substr(space_pos + 1, colon_pos - space_pos - 1);
		auto closing_bracket_pos = line.find("]");
		auto minute_str = line.substr(colon_pos + 1, closing_bracket_pos - colon_pos - 1);
		unsigned minute = 0;
		if (hour_str == "23") day++;
		else minute = std::stoi(minute_str);
		timestamp_t ts{ month, day, minute };
		auto first_letter_pos = closing_bracket_pos + 2;
		guard_status_t gs;
		unsigned number = 0;
		if (line[first_letter_pos] == 'G') {
			gs = BEGINS;
			auto hash_pos = line.find("#");
			auto space_after_hash_pos = line.find(" ", hash_pos + 1);
			auto number_str = line.substr(hash_pos + 1, space_after_hash_pos - hash_pos - 1);
			number = std::stoi(number_str);
		}
		else if (line[first_letter_pos] == 'f') gs = FALLS_ASLEEP;
		else if (line[first_letter_pos] == 'w') gs = WAKES_UP;
		entry_t entry{ number, gs, ts };
		entries.push_back(entry);
	}
	std::sort(entries.begin(), entries.end(), sort_func);
	unsigned prev_number = entries[0].guard_number;
	for (auto &entry : entries) {
		if (entry.guard_number != 0) {
			prev_number = entry.guard_number;
		}
		else if (entry.guard_number == 0) {
			entry.guard_number = prev_number;
		}
	}
	std::map<unsigned, unsigned> total_minutes_asleep_map;
	std::map<unsigned, std::vector<unsigned>> minute_by_minute_asleep_map;
	int falls_asleep_time = -1, wakes_up_time = -1;
	unsigned number = 0;
	for (unsigned i = 0; i < entries.size(); i++) {
		if (entries[i].status == BEGINS) {
			number = entries[i].guard_number;
		}
		else if (entries[i].status == FALLS_ASLEEP) {
			falls_asleep_time = entries[i].timestamp.minute;
		}
		else if (entries[i].status == WAKES_UP) {
			wakes_up_time = entries[i].timestamp.minute;
			if (total_minutes_asleep_map[number])
				total_minutes_asleep_map[number] += wakes_up_time - falls_asleep_time;
			else total_minutes_asleep_map[number] = wakes_up_time - falls_asleep_time;
			if (!minute_by_minute_asleep_map[number].empty()) {
				for (unsigned i = falls_asleep_time; i < wakes_up_time; i++) {
					minute_by_minute_asleep_map[number][i]++;
				}
			}
			else {
				minute_by_minute_asleep_map[number] = std::vector<unsigned>(60, 0);
				for (unsigned i = falls_asleep_time; i < wakes_up_time; i++) {
					minute_by_minute_asleep_map[number][i]++;
				}
			}
			falls_asleep_time = -1;
			wakes_up_time = -1;
		}
		
	}
	unsigned max_time_asleep = 0, max_time_asleep_number = 0;
	for (const auto &pair : total_minutes_asleep_map) {
		if (pair.second > max_time_asleep) {
			max_time_asleep = pair.second;
			max_time_asleep_number = pair.first;
		}
	}
	int minute_most_asleep = -1, unique_mins_asleep = 0;
	for (unsigned i = 0; i < minute_by_minute_asleep_map[max_time_asleep_number].size(); i++) {
		if (minute_by_minute_asleep_map[max_time_asleep_number][i] > unique_mins_asleep) {
			unique_mins_asleep = minute_by_minute_asleep_map[max_time_asleep_number][i];
			minute_most_asleep = i;
		}
	}
	std::cout << "max time asleep pair: "
		<< max_time_asleep_number << '+' << minute_most_asleep << '\n';
	return 0;
}