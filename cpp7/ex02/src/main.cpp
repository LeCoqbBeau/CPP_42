//
// Created by mscheman on 8/16/24.
//

#include "array.h"
#include "iter.h"

typedef enum e_zone {
	ALPHA = 0,
	BRAVO,
	CHARLIE,
	DELTA,
	ECHO,
	E_ZONE_END
} t_zone;

typedef struct s_drill {
	// Constructors
	s_drill(const t_zone zone = ALPHA, const size_t veinDensity = 0, str cref ore = "Nothing")
			: sector(zone), output(veinDensity), type(ore) {};
	// Attributes
	t_zone	sector;
	size_t	output;
	str		type;
}	t_drill;

static std::string zoneToStr(t_zone zone);
static void examine(t_drill cref drill);

int main() {
	Array<t_drill> drills(5);

	NEWL;
	PRINT PRP BOLD "-----[ Initiating Sector Alpha Expansion Process ]-----" CENDL;
	NEWL;

	PRINT PRP " Producing drills, number expected: 10" CENDL;
	for (int i = 0; i < 10; ++i) {
		try {
			drills[i] = t_drill(ALPHA, 70, "Diamond");
			PRINT "  Successfully produced drill number " AND i ENDL;
		} catch (std::exception ref e) {
			ERROR RED BOLD "  Not enough resources for drill number " AND i CENDL;
		}
	}
	PRINT PRP " Produced and deployed " CLR AND drills.size() AND PRP " drills on ALPHA" CENDL;

	NEWL;
	PRINT PRP " Now examining all new drills behaviour:" CENDL;
	::iter(drills.data(), drills.size(), examine);

	NEWL;
	PRINT PRP BOLD "-----[ Terminated Sector Alpha Expansion Process ]-----" CENDL;
	NEWL;

	NEWL;
	PRINT PRP BOLD "-----[ Initiating Sector Bravo Expansion Process ]-----" CENDL;
	NEWL;

	Array<t_drill> motors(10);
	PRINT PRP " Producing 10 drills:" CENDL;
	std::fill_n(motors.data(), motors.size(), t_drill(BRAVO, 115, "Gold"));
	::iter(motors.data(), motors.size(), examine);
	NEWL;
	PRINT GRN BOLD " NEW DIAMOND VEIN DISCOVERED ON SECTOR ALPHA" CENDL;
	PRINT PRP " Repurposing Sector Bravo's drills into diamond drill" CENDL;
	motors = drills;
	NEWL;
	PRINT PRP " Now examining all scraped drills behaviour:" CENDL;
	::iter(motors.data(), motors.size(), examine);

	NEWL;
	PRINT PRP BOLD "-----[ Terminated Sector Bravo Expansion Process ]-----" CENDL;
	NEWL;
	// {
	// 	Array<t_drill> test = drills;
	// 	::iter(test.data(), test.size(), printDrill);
	// }
}

static std::string zoneToStr(const t_zone zone) {
	switch (zone) {
		case ALPHA:
			return "ALPHA";
		case BRAVO:
			return "BRAVO";
		case CHARLIE:
			return "CHARLIE";
		case DELTA:
			return "DELTA";
		case ECHO:
			return "ECHO";
		case E_ZONE_END:
			return "UNKNOWN";
	}
}

static void examine(t_drill cref drill) {
	PRINT TAB;
	PRINT YLW BOLD "Drill on " CLR AND zoneToStr(drill.sector);
	PRINT YLW BOLD " producing " CLR AND  drill.output AND " " AND drill.type ;
	PRINT YLW BOLD "/day." CLR;
	NEWL;
}
