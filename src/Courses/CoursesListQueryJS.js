import React from 'react';
import gql from "graphql-tag";
import { Query } from "react-apollo";

import CourseListCourse from './CourseListCourse.bs';

// const CourseListCourse = require('./CourseListCourse.bs').jsComponent;


const GET_COURSES = gql`
  query courses {
    courses {
			name
    }
  }
`;

export default class extends React.Component {
	render() {
		return (
			<Query query={GET_COURSES}>
				{
					({loading, error, data}) => {
						if (loading) return "Loading";
						if (error) return "error";
						return data.map(
							course =>
								<CourseListCourse course={course} />
						);
					}
				}
			</Query>
		)
	}
}