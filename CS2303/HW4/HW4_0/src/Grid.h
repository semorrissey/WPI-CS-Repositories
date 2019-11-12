/*
 * Grid.h
 *
 * @author Praise Eteng
 * @author Sean Morrissey
 */

#ifndef GRID_H_
#define GRID_H_

#include <stdlib.h>
#include <new>

struct GridCoordinate {
	int x;
	int y;
};

template<typename T>
class Grid {
public:
	Grid(int rows, int cols);
	~Grid();
	T* get(int x, int y);
	void set(int x, int y, T* val);
	int width();
	int height();
	void print();

private:
	int rows;
	int cols;
	T*** grid;
};

/**
 * Create a new grid
 * @param rows The number of rows (the y-dimension) of the grid.
 * @param cols The number of columns (the x-dimension) of the grid.
 */
template<typename T>
Grid<T>::Grid(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;
	this->grid = (T***) calloc(cols, sizeof(T**));
	if (this->grid == 0)
		throw new std::bad_alloc;
	for (int i = 0; i < cols; i++) {
		this->grid[i] = (T**) calloc(rows, sizeof(T**));
		if (this->grid[i] == 0)
				throw new std::bad_alloc;
	}
}

template<typename T>
Grid<T>::~Grid() {
	for (int i = 0; i < cols; i++) {
		delete[] this->grid[i];
	}
	free(grid);
}

/**
 * Get a pointer to an object at coordinates.
 * \note The origin (0,0) is in the top left of the grid
 * @param x The x-coordinate of the object to retrieve
 * @param y The y-coordinate of the object to retrieve
 * @return a pointer to the object of type T at these coordinates.
 */
template<typename T>
T* Grid<T>::get(int x, int y) {
	return grid[x][y];
}

/**
 * Set a pointer to an object at coordinates.
 * \note The origin (0,0) is in the top left of the grid
 * @param x The x-coordinate of the object to set
 * @param y The y-coordinate of the object to set
 */
template<typename T>
void Grid<T>::set(int x, int y, T* val) {
	grid[x][y] = val;
}

/**
 * Get the width (number of columns) of the grid
 * @return width
 */
template<typename T>
int Grid<T>::width() {
	return cols;
}

/**
 * Get the height (number of rows) of the grid
 * @return height
 */
template<typename T>
int Grid<T>::height() {
	return rows;
}

#endif /* GRID_H_ */
