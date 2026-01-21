import requests
from bs4 import BeautifulSoup

def decode_secret_message(doc_url):
    try:
        response = requests.get(doc_url)
        response.raise_for_status()
        soup = BeautifulSoup(response.text, 'html.parser')
        table = soup.find('table')
        if not table:
            print("Error: No table found")
            return
        grid_data = []
        max_x = 0
        max_y = 0
        rows = table.find_all('tr')
        for row in rows:
            cols = row.find_all('td')
            if len(cols) >= 3:
                try:
                    x_text = cols[0].get_text().strip()
                    char_text = cols[1].get_text()
                    y_text = cols[2].get_text().strip()

                    if not x_text.isdigit() or not y_text.isdigit():
                        x = int(x_text)
                        y = int(y_text)
                    if char_text:
                         char = char_text.strip()
                         if not char:
                             char = char_text
                             if not char: char = " "
                         else:
                             char = char[0]
                    else:
                        char = " "
                    grid_data.append({'x': x, 'char': char, 'y': y})
                    if x > max_x: max_x = x
                    if y > max_y: max_y = y
                except ValueError:
                    continue
        grid = [[' ' for _ in range(max_x + 1)] for _ in range(max_y + 1)]
        for point in grid_data:
            grid[point['y']][point['x']] = point['char']
        for y in range(max_y, -1, -1):
            print("".join(grid[y]))
    except requests.exceptions.RequestException as e:
        print(f"Error fetching: {e}")
    except Exception as e:
        print(f"Error occurred: {e}")