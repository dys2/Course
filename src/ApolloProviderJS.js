import React from 'react';
import { ApolloProvider } from 'react-apollo';

import apolloClient from './apolloClient';

export default class extends React.Component {
	render() {
		return (
			<ApolloProvider client={apolloClient}>
				{this.props.children}
			</ApolloProvider>
		)
	}
}