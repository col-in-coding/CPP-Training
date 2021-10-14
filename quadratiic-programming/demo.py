import osqp
import numpy as np
from scipy import sparse
import matplotlib.pyplot as plt


class Smoother:

    weight_fem_pos_deviation = 1e10
    weight_path_length = 1
    weight_ref_deviation = 1

    def __init__(self, ref_points, bounds_around_refs) -> None:
        self.ref_points = ref_points
        self.bounds_around_refs = bounds_around_refs

    def calculate_kernel(self, num_of_points):
        weight_fem_pos_deviation = self.weight_fem_pos_deviation
        weight_path_length = self.weight_path_length
        weight_ref_deviation = self.weight_ref_deviation

        num_of_variables = num_of_points * 2

        P_data = []
        P_indices = []
        P_indptr = []

        colomns = [[] for _ in range(num_of_variables)]
        col_num = 0
        for col in range(0, 2):
            colomns[col].append((col, weight_fem_pos_deviation + weight_path_length + weight_ref_deviation))
            col_num += 1

        for col in range(2, 4):
            colomns[col].append((col - 2, -2 * weight_fem_pos_deviation - weight_path_length))
            colomns[col].append((col, 5 * weight_fem_pos_deviation + 2 * weight_path_length + weight_ref_deviation))
            col_num += 1
        
        for point_idx in range(2, num_of_points - 2):
            col_idx = point_idx * 2
            for col in range(0, 2):
                col_idx += col
                colomns[col_idx].append((col_idx - 4, weight_fem_pos_deviation))
                colomns[col_idx].append((col_idx - 2, -4 * weight_fem_pos_deviation - weight_path_length))
                colomns[col_idx].append((col_idx, 6 * weight_fem_pos_deviation + 2 * weight_path_length + weight_ref_deviation))
                col_num += 1
        
        for col in range(num_of_variables - 4, num_of_variables - 2):
            colomns[col].append((col - 4, weight_fem_pos_deviation))
            colomns[col].append((col - 2, -4 * weight_fem_pos_deviation - weight_path_length))
            colomns[col].append((col, 5 * weight_fem_pos_deviation + 2 * weight_path_length + weight_ref_deviation))
            col_num += 1

        for col in range(num_of_variables - 2, num_of_variables):
            colomns[col].append((col - 4, weight_fem_pos_deviation))
            colomns[col].append((col - 2, -2 * weight_fem_pos_deviation - weight_path_length))
            colomns[col].append((col, weight_fem_pos_deviation + weight_path_length + weight_ref_deviation))
            col_num += 1


        ind_p = 0
        for i in range(0, col_num):
            P_indptr.append(ind_p)
            for row_data_pair in colomns[i]:
                P_data.append(row_data_pair[1] * 2)
                P_indices.append(row_data_pair[0])
                ind_p += 1
        
        P_indptr.append(ind_p)
        P = sparse.csc_matrix((P_data, P_indices, P_indptr))
        return P


    def calculate_offset(self, num_of_points, ref_points):
        q = []
        for i in range(0, num_of_points):
            ref_point_xy = ref_points[i]
            q.append(-2 * self.weight_ref_deviation * ref_point_xy[0])
            q.append(-2 * self.weight_ref_deviation * ref_point_xy[1])
        return q

    def calculate_affine_constraint(self, num_of_points, ref_points, bounds_around_refs):
        ind_A = 0
        A_data = []
        A_indices = []
        A_indptr = []
        for i in range(num_of_points * 2):
            A_data.append(1)
            A_indices.append(i)
            A_indptr.append(ind_A)
            ind_A += 1
        A_indptr.append(ind_A)
        A = sparse.csc_matrix((A_data, A_indices, A_indptr))

        upper_bounds = []
        lower_bounds = []
        for i in range(num_of_points):
            ref_point_xy = ref_points[i]
            upper_bounds.append(ref_point_xy[0] + bounds_around_refs[i])
            upper_bounds.append(ref_point_xy[1] + bounds_around_refs[i])
            lower_bounds.append(ref_point_xy[0] - bounds_around_refs[i])
            lower_bounds.append(ref_point_xy[1] - bounds_around_refs[i])
        return A, upper_bounds, lower_bounds

    def smooth(self):
        ref_points = self.ref_points
        num_of_points = len(ref_points)
        P = self.calculate_kernel(num_of_points)
        q = self.calculate_offset(num_of_points, ref_points)
        A, upper_bounds, lower_bounds = self.calculate_affine_constraint(num_of_points, ref_points, bounds_around_refs)

        q = np.asarray(q)
        u = np.asarray(upper_bounds)
        l = np.asarray(lower_bounds)

        # Create an OSQP object
        prob = osqp.OSQP()

        x_warm_start = []
        for i in range(num_of_points):
            x_warm_start.append(ref_points[i][0])
            x_warm_start.append(ref_points[i][1])
        x_warm_start = np.asarray(x_warm_start)

        prob.setup(P, q, A, l, u, alpha=1, warm_start=True, verbose=True)
        prob.warm_start(x=x_warm_start)

        # # Solve problem
        res = prob.solve()
        return res


if __name__ == "__main__":
    ref_points = [(1, 1), (1.05, 1.27), (1.1, 1.5), (1.25, 1.7), (1.5, 1.75), (1.75, 1.6)]
    num_of_points = len(ref_points)
    bounds_around_refs = [0.05 for _ in range(num_of_points)]
    fig, ax = plt.subplots()
    x1 = [p[0] for p in ref_points]    
    y1 = [p[1] for p in ref_points]    
    ax.plot(x1, y1)
    
    smoother = Smoother(ref_points, bounds_around_refs)
    res = smoother.smooth()

    x2 = []
    y2 = []
    for i in range(num_of_points):
        x2.append(res.x[i * 2])
        y2.append(res.x[i * 2 + 1])

    ax.plot(x2, y2)
    plt.show()