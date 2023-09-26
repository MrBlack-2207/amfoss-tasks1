import requests
from bs4 import BeautifulSoup

def retrieve_live_scores():
    """
    Retrieves live cricket scores from ESPN website that u provided.

    it gives :
        team_data : List of team names.
        score_status_data : List of tuples containing scores and match statuses.
    """
    response = requests.get('https://www.espncricinfo.com/live-cricket-score')

    if response.status_code == 200:
        soup = BeautifulSoup(response.text, 'html.parser')

        team_name_elements = soup.find_all(class_='ci-team-score ds-flex ds-justify-between ds-items-center ds-text-typo ds-my-1')
        score_elements = soup.find_all(class_='ds-text-tight-s ds-font-regular ds-truncate ds-text-typo')
        status_elements = soup.find_all(class_='ds-text-tight-xs ds-truncate ds-text-typo-mid3')

        team_data = []
        score_status_data = []

        for i in range(2):
            team_name = team_name_elements[i].get_text(strip=True)
            team_data.append(team_name)

            team_score = score_elements[i].get_text(strip=True)
            match_status = status_elements[i].get_text(strip=True)
            score_status_data.append((team_score, match_status))

        return team_data, score_status_data

    else:
        return None, None
