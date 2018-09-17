import React from 'react';
import gql from "graphql-tag";
import { Query } from "react-apollo";

// const CourseListCourse = require('./CourseListCourse.bs').jsComponent;


const GET_COURSES = gql`
  query courses {
    courses {
			name
    }
  }
`;

export default class extends React.Component {
	componentDidMount() {
		console.log('sdfsdfd');
	}
	render() {
		return (
			<div>
			<h1>DFSDFSD</h1>
			<Query query={GET_COURSES}>
				{
					({loading, error, data}) => {
						console.log('dsfsdf', data);
						if (loading) return "Loading";
						if (error) return "error";
						return <div></div>
					}
				}
			</Query>
			</div>
		)
	}
}