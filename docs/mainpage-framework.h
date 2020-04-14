/**

@{

\brief Implementation of a dissipation energy-based arc-length method in deal.ii

\author jfriedlein

@tableofcontents

@mainpage Hybrid solution method with dissipation energy-based arc-length method

@section intro Introduction



@subsection subsec_overview Overview
This overview shall give you a first impression what to expect ...
@todo add the flow chart from the MA

@subsection subsec_interface Interface - How to incorporate the solution method into your code

- First you have to include the header file \a hybrid_solver.h
	@code
	#include "hybrid_solver.h"
	@endcode
- Create a global instance (e.g. hybridSolver) of the \a hybrid_solver class to be able to store and access data
  related to the solution method
  @code
  hybrid_solver<dim> hybridSolver;
  @endcode
  @todo Check whether we need the template<int dim> for some reason
- Initialise the instance with the initial load increment \a initial_increment (applied in the first load step),
	the driver (Neumann=1, Dirichlet=2) that applies the load
	and the number of dofs per cell \a dofs_per_cell (e.g. from \a fe.dofs_per_cell)
  @code
  hybridSolver(initial_increment, driver, dofs_per_cell)
  @endcode
- Store the total number of dofs \a n_dofs in the same-named member variable
	@code
	hybridSolver.n_dofs = dof_handler.n_dofs();
	@endcode
- Store an std::vector<bool> containing the true or false that assigns the dof i with the displacement field.
	It is true when i holds a displacement value and false if it does not. This becomes important for
	two- or more-field problems where the solution vectors contains
	besides the desired displacement values also other fields such as the damage field.
	hybridSolver.u_dofs = u_dofs;
- Reinitialise the internal vectors of the solution method best at the same place
	where the tangent matrix \a tangent_matrix and the right-hand side \a system_rhs are reinitialised (= set to the correct size).
	@code
	std::vector<bool> u_dofs;
	u_dofs.resize( dof_handler.n_dofs() );
	ComponentMask u_mask(fe.component_mask (u_fe) ); // u_fe numbers the first dof per node that belongs to the displacements (followed by the y and possibly z-component)
	DoFTools::extract_dofs(dof_handler, u_mask, u_dofs);
	hybridSolver.reinit_vectors();
	@endcode


@todo Format the code below, use subheadings, etc.

@subsection subsec_more_basics Some more basics



@subsection subsec_resources Some resources/links



@section code The commented program

\code
example_code_to_be_documented.cc
\endcode

@section END The End

Hosted via GitHub according to https://goseeky.wordpress.com/2017/07/22/documentation-101-doxygen-with-github-pages/ \n
Design of the documentation inspired by the deal.ii tutorial programs.

@}
*/
